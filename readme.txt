This repo contains a Brainf**k interpreter in C, and one in Python. 

Barry Rountree, my mentor at LLNL during summer 2017, had me write them to better understand Nanopond.
The instruction set that the cells use is similar to that of Bf.

In Bf, one can increment or decrement a pointer to the data array and the byte at that index; input or output that byte;
and have a loop of other Bf instructions.

In Nanopond, 4 bit numbers represent unique cell instructions in each cell's genome.
Cells also have a register that acts like a notepad for reading or writing, a buffer and a pointer to its own genome.
They can increment or decrement the register and the genome pointer, write to the register or buffer from its own genome, loop its instructions, skip an instruction and replace it with the value of the register, turn, and share energy or kill a neighbor.
After being executed, every cell will attempt to reproduce into the neighbor it is facing by copying its buffer into its genome.

Understanding how this is set up requires understanding bit shifting, structs, pointers and arrays in C.
Writing the Bf interpreter in C was a great first introduction to working with those concepts hands on.
