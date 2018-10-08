CC = gcc
CFLAGS = -O0 -g -Wall -Werror

test: sorted_linked_list.h sorted_linked_list.c linked_list_test.c
	$(CC) $(CFLAGS) -o test sorted_linked_list.c linked_list_test.c
	./test