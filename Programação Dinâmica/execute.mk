CC = gcc
CFLAGS = -Wall -Werror

all:	input coin output

input:	input.txt
		@echo "Input"
		@cat input.txt
		@echo " "

coin:	coinChange.c
		@ $(CC) $(CFLAGS) coinChange.c -o coinChange
		@echo "Program output"
		@cat input.txt | ./coinChange
		
output:	output.txt
		@echo "Expected output"
		@cat output.txt
		@echo " "
