CC = gcc
CFLAGS = -Wall -Werror

all:	selection quicksort mergesort insertion heapsort

selection:	selection.c
	$(CC) $(CFLAGS) selection.c -o selection

quicksort:	quicksort.c
	$(CC) $(CFLAGS) quicksort.c -o quicksort

mergesort:	mergesort.c
	$(CC) $(CFLAGS) mergesort.c -o mergesort

insertion:	insertion.c
	$(CC) $(CFLAGS) insertion.c -o insertion

heapsort: heapsort.c
	$(CC) $(CFLAGS) heapsort.c -o heapsort	