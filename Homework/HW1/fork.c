#include <stdio.h>

// This program runs a command through a forked child process

int main(int argc, char *argv[]) {

	// Create pid for reference
	int pid;
	pid = fork();

	// Create an array of only vars.

	if (pid < 0) {
		printf(stderr, "Fork failed");
		return -1;
	}
	else if (pid == 0) {
		printf("\nChild PID: %d    Parent PID: %d\n\n", getpid(), getppid());

		execvp(argv[1], argv+1);
	}
	else {
		wait(NULL);
	}

	return 0;
}