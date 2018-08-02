CC=gcc
FLAGS=-pthread
ARGS=-o

all:
	$(CC) $(FLAGS) $(ARGS) noMutex noMutex.c
	$(CC) $(FLAGS) $(ARGS) mutex mutex.c

.PHONY: clean
clean: 
	rm -f noMutex mutex