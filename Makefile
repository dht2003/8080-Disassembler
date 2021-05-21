dissassembler : main.c dissassembler.c	
	gcc -Wall -o dissassembler main.c  dissassembler.c

clean :
	rm dissassembler