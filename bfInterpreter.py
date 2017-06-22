class bfInterpreter:
  
  # Constructor initializes data and instruction arrays as well as data and instruction pointers to 0's
	def __init__(self, input_data, input_instr):
		print("instantiated")
		self.data = input_data
		self.instructions = input_instr
		self.data_pointer = 0
		self.instr_pointer = 0
		self.bracket_stack = []
		
		
		

  # Moves data pointer to the next cell in data array
	def incDataPointer(self):
		#print("\n Executing incDataPointer function.    " + "data pointer: " + str(self.data_pointer) + "   instruction pointer: " + str(self.instr_pointer) + "     current data byte: " + str(self.data[self.data_pointer]))
		
		self.data_pointer += 1
		
		# Incrementing instruction pointer to next command
		self.instr_pointer += 1
		
		
		
	# Moves data pointer to the previous cell in data array	
	def decDataPointer(self):
		#print("\n Executing decDataPointer function.    " + "data pointer: " + str(self.data_pointer) + "   instruction pointer: " + str(self.instr_pointer) + "    current data byte: " + str(self.data[self.data_pointer]))
		
		self.data_pointer -= 1
		
		# Incrementing instruction pointer to next command
		self.instr_pointer += 1
		
		
	  
	# Increments byte at cell pointed at by data pointer
	def incCurrData(self):
		#print("\n Executing incCurrData function.    " + "data pointer: " + str(self.data_pointer) + "   instruction pointer: " + str(self.instr_pointer) + "     current data byte: " + str(self.data[self.data_pointer]))
		
		self.data[self.data_pointer] += 1
		
		# Incrementing instruction pointer to next command
		self.instr_pointer += 1
		
		
		
	# Decrements byte at cell pointed at by data pointer
	def decCurrData(self):
		#print("\n Executing decCurrData function.    " + "data pointer: " + str(self.data_pointer) + "   instruction pointer: " + str(self.instr_pointer) + "     current data byte: " + str(self.data[self.data_pointer]))
		
		self.data[self.data_pointer] -= 1
		
		# Incrementing instruction pointer to next command
		self.instr_pointer += 1
		
		
	  
	# Prints out ASCII character corresponding to integer in data cell pointed to currently
	def printOutput(self):
		#print("\n Executing printOutput function.    " + "data pointer: " + str(self.data_pointer) + "   instruction pointer: " + str(self.instr_pointer) + "    current data byte: " + str(self.data[self.data_pointer]))
		
		print(chr(self.data[self.data_pointer]), end="")
		
		# Incrementing instruction pointer to next command
		self.instr_pointer += 1
	  
	# Only executes next command if current data is non-zero; otherwise skips past next ]
	def beginLoop(self):
		#print("\n Executing beginLoop function.    " + "data pointer: " + str(self.data_pointer) + "   instruction pointer: " + str(self.instr_pointer) + "    current data byte: " + str(self.data[self.data_pointer]))
		
		self.bracket_stack.append(self.instr_pointer)
		#print("OPEN BRACKET ADDED TO STACK")
		
		# Incrementing instruction pointer to next command
		self.instr_pointer += 1
	  
	# Returns instruction pointer to after the most recent [ if current data is non-zero
	def endLoop(self):
		#print("\n Executing endLoop function.    " + "data pointer: " + str(self.data_pointer) + "   instruction pointer: " + str(self.instr_pointer) + "    current data byte: " + str(self.data[self.data_pointer]))
		
		openBrackPos = self.bracket_stack.pop()
		#print("OPEN BRACK TAKEN FROM STACK")
		
		if self.data[self.data_pointer] != 0:
			self.instr_pointer = openBrackPos
		else:
			# Incrementing instruction pointer to next command
			self.instr_pointer += 1	
		
		
			
	  
	# Main loop of carrying out instructions 
	def doInstructions(self):
	  #print("Instructions function called")
      
    # Could go before or after actually carrying out command at instruction pointer
	  while len(self.instructions) > self.instr_pointer:
	    # Maps BF commands to the python functions simulating them
	    if self.instructions[self.instr_pointer] == ".":
	      self.printOutput()
	    elif self.instructions[self.instr_pointer] == ">":
	      self.incDataPointer()
	    elif self.instructions[self.instr_pointer] == "<":
	    	self.decDataPointer()
	    elif self.instructions[self.instr_pointer] == "+":
	    	self.incCurrData()
	    elif self.instructions[self.instr_pointer] == "-":
	    	self.decCurrData()
	    elif self.instructions[self.instr_pointer] == "[":
	    	self.beginLoop()
	    elif self.instructions[self.instr_pointer] == "]":
	    	self.endLoop()
	  
	  
	  
	  
# if __name__ == "__main__":
new = bfInterpreter([0 for i in range(0,13)], "+++++++++[>++++++++[>+<-]<-]>>." + "<<++++++++++[>++++++++++[>>+<<-]<-]>>>+." + "<<<++++++++++++[>+++++++++[>>>+<<<-]<-]>>>>." + "<<<<++++++++++++[>+++++++++[>>>>+<<<<-]<-]>>>>>." + "<<<<<+++++++++++[>++++++++++[>>>>>+<<<<<-]<-]>>>>>>+." + "<<<<<<++++[>++++++++[>>>>>>+<<<<<<-]<-]>>>>>>>." + "<<<<<<<+++++[>+++++++++++++++++[>>>>>>>+<<<<<<<-]<-]>>>>>>>>++." + "<<<<<<<<++++++++++[>+++++++++++[>>>>>>>>+<<<<<<<<-]<-]>>>>>>>>>+.")
new.doInstructions() 















