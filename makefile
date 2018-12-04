OBJS  = tree_test.o binary_tree.o
ASFLAGS = -ggdb -Wall -fsanitize=leak
CC = gcc

binary_tree: $(OBJS)
	$(CC) $(ASFLAGS) $^ -o binary_tree 

.PHONY: clean
clean:
	rm -f *.o binary_tree
