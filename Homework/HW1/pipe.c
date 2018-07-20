#include <stdio.h>

int main() {
	
	int pid1;
	int fd[2];
	
	/**
	Create pipe
	**/
	pipe(fd);	
	
	/**
	Create child
	**/
	pid = fork();
	
	if (pid < 0) {
		printf("ERROR! CHILD NOT CREATED");
	}
	
	/**
	Set parent to accept input
	**/
	else if (pid > 0) {
		
	}
	
	/**
	Set input of p2 as output of p1
	**/
	
	/**
	Execute program
	**/
	
	
	
	return 0;
}