CC=gcc
FLAGS=-w
ARGS=-o

all:
	$(CC) $(FLAGS) $(ARGS) sort sort.c
	$(CC) $(FLAGS) $(ARGS) pre pre.c
	$(CC) $(FLAGS) $(ARGS) fork fork.c

.PHONY: clean
clean:
	-rm sort pre fork
