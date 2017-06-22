#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void bf_helloworld();

void bf_helloworld(){

    uint8_t d[3000] = {0};  // data array
    uint8_t i[3000] = {"+++++++++[>++++++++[>+<-]<-]>>. "}; // instructions array
    uint64_t s[3000] = {0}; // stack
    uint64_t d_idx = 0, i_idx = 0, s_idx = -1;
    int j;
    
    while (i[i_idx] != ' ') {
        printf("instruction index: %llu    instruction: %c    data index: %llu    data in data index: %hhu    stack index: %llu    stack pos in stack index: %llu\n", i_idx, i[i_idx], d_idx, d[d_idx], s_idx, s[s_idx]);

        printf("data array ");
        for (j = 0; j < 10; j++) {
            printf(" %hhu ", d[j]);
        }
        printf("\n");
        switch (i[i_idx]) {
            case '>':   d_idx++;    i_idx++;    printf("data pointer is now: %llu\n", d_idx);   break;
            case '<':   d_idx--;    i_idx++;    printf("data pointer is now: %llu\n", d_idx);   break;
            case '+':   d[d_idx]++; i_idx++;    printf("data bit is now: %hhu\n", d[d_idx]);   break; 
            case '-':   d[d_idx]--; i_idx++;    printf("data bit is now: %hhu\n", d[d_idx]);   break; 
            case '.':   printf("%c", d[d_idx]); i_idx++;    break;
            case '[':   s_idx++;    s[s_idx] = i_idx;    i_idx++;  break;
            case ']':   if (d[d_idx] != 0) 
                        {
                            i_idx = s[s_idx] + 1;
                        } else 
                        {
                            i_idx++;
                            s[s_idx] = 0;
                            s_idx--;
                        }
                        break;
            default:    printf("Should never get here.\n"); exit(0);    break;
        }

    }
    printf("\n");
}

void encode(){
    uint64_t instr_in_bits[3000] = {0};
    // printf("instr_in_bits[2699] is %llu\n", instr_in_bits[2699]);
    uint8_t charas[3000] = {"+++++++++[>++++++++[>+<-]<-]>>. "}; // instructions array

    // uint64_t mask,  input, sampl;
    /*
    if (i[2600 == 0]) {
        printf("i[2699] is %hhu\n", i[2699]);
    }
    input = 0xabcdabcdabcdabc4;
    sampl = 0x000000000000000b;
    mask =  0x0000000000000004;

    printf("sampl is %016llx and mask is %016llx\n", sampl, mask);
    printf("AND of sampl and mask is %016llx\n", (sampl&mask));
    printf("OR of sampl and mask is %016llx\n", (sampl|mask));
    */

    int a = 0, j = 0; // number of 64 bit numbers encoded with instructions
    while (charas[(j * 16) + a] != 0) {
            uint64_t curr_cmd; 

            switch (charas[(j * 16) + a]) {
                case ' ':  curr_cmd = 0;    break;
                case '>':  curr_cmd = 1;    break;
                case '<':  curr_cmd = 2;    break;
                case '+':  curr_cmd = 3;    break;
                case '-':  curr_cmd = 4;    break;
                case '.':  curr_cmd = 5;    break;
                case '[':  curr_cmd = 6;    break;
                case ']':  curr_cmd = 7;    break;
            }
           printf("j cell to add on to: %d\n", j); 
           printf("add %016llx to %016llx\n", curr_cmd << (a * 4), instr_in_bits[j]);

           instr_in_bits[j] += curr_cmd << a * 4; 
 
            printf("encoded instruction number: %016llx\n", instr_in_bits[j]); 
           
            a++;
            if (a > 15) {
                a = 0;
                j++;
            }
    }
}

void decode() {
    uint64_t coded_instr[10] = {0};
    coded_instr[0] = 0x3333316333333333;
    coded_instr[1] = 0x0511742742316333; 
    uint8_t chars[3000] = {0};
    
    int a = 0, j = 0;
    uint64_t mask = 0x000000000000000f;
    while (coded_instr[j] != 0) {
        printf("%d: mask %016llx & instruction string %016llx is %016llx\n", j * 16 + a, mask, coded_instr[j], mask & coded_instr[j]);
        chars[j * 16 + a] = (mask & coded_instr[j]) >> a * 4;
        printf("instruction to be translated is %016hhx\n", chars[j * 16 + a]);
        
        switch (chars[j * 16 + a]) {
            case 0: chars[j * 16 + a] = ' ';    printf("bf instruction is %c\n", chars[j * 16 + a]);    break;
            case 1: chars[j * 16 + a] = '>';    printf("bf instruction is %c\n", chars[j * 16 + a]);    break;
            case 2: chars[j * 16 + a] = '<';    printf("bf instruction is %c\n", chars[j * 16 + a]);    break;
            case 3: chars[j * 16 + a] = '+';    printf("bf instruction is %c\n", chars[j * 16 + a]);    break;
            case 4: chars[j * 16 + a] = '-';    printf("bf instruction is %c\n", chars[j * 16 + a]);    break;
            case 5: chars[j * 16 + a] = '.';    printf("bf instruction is %c\n", chars[j * 16 + a]);    break;
            case 6: chars[j * 16 + a] = '[';    printf("bf instruction is %c\n", chars[j * 16 + a]);    break;
            case 7: chars[j * 16 + a] = ']';    printf("bf instruction is %c\n", chars[j * 16 + a]);    break;
            }

        mask = mask << 4;

        a++;
        if (a > 15) {
            j++;
            a = 0;
            mask = 0x000000000000000f;
        }
    }
}

int main(){
    //bf_helloworld();
    
    encode();
    decode();

    printf("IT DOES THE THING!!!!");

}
