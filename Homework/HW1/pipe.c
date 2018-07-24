#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	
	char buf[20];
	int pid;
	int fd[2];
	
	/**
	Create pipe
	**/
	if (pipe(fd) == -1)
		printf("ERROR! PIPE NOT CREATED for some reason.");	
	
	/**
	Create child
	**/
	pid = fork();
	
	if (pid < 0) {
		printf("ERROR! CHILD NOT CREATED for some reason");
	}
	
	/**
	Set parent to read from pipe
	**/
	else if (pid > 0) {	
		char *argv[] = {"sort", NULL}; // Exec arguments

		close(0);
		dup(fd[0]);
		close(fd[0]);
		close(fd[1]);

		if(execl(argv[0], argv, NULL) == -1)
			printf("EXEC2 FAILED\n\n");
	}
	
	/**
	Set child to write to pipe
	**/
	else {
		char *argv[] = {"pre", NULL}; // Exec arguments

		close(1);
		dup(fd[1]);
		close(fd[1]);
		close(fd[0]);
		if(execl(argv[0], argv, NULL) == -1)
			printf("EXEC1 FAILED\n\n");
		printf("CHILD FINISHED");
	}
	
	/**

		
	/**
	Execute program
	**/
	
	
	
	return 0;
}