CC = gcc
CFLAGS = -Wall -Werror

all:	color_sorting find_sorted linked_list_quicksort_value linked_list_quicksort_pointer

color_sorting:	color_sorting.c
	$(CC) $(CFLAGS) color_sorting.c -o color_sorting

find_sorted:	find_sorted.c
	$(CC) $(CFLAGS) find_sorted.c -o find_sorted

linked_list_quicksort_value: linked_list_quicksort_value.c
	$(CC) $(CFLAGS) linked_list_quicksort_value.c -o linked_list_quicksort_value

linked_list_quicksort_pointer: linked_list_quicksort_pointer.c
	$(CC) $(CFLAGS) linked_list_quicksort_pointer.c -o linked_list_quicksort_pointer
