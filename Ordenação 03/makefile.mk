CC = gcc
CFLAGS = -Wall -Werror

all:	read

read:	read.c
	$(CC) $(CFLAGS) read.c -o read