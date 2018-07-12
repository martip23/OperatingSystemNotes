#include <stdio.h>

void main (int argc, char* argv[])
{
	int pid;
	pid = fork();
	printf("hello");	// How many times will "hello" print. - 4 times
						// Twice here
	if (pid < 0)
		{
			fprintf(stderr, "Fork failed");
			exit(-1);
		}
	else if (pid == 0)
		{
			printf("hello"); // Will print
			execlp("/bin/ls", "ls", NULL);
			printf("hello"); // Will not print.
		}
	else
		{
			printf("hello"); // Will Print
			wait(NULL); // If no wait, then child is dead, parent alive.
						// We need to kill zombie. $kill -9 pid
						// To remove zombie, we must kill parent.
						// If you kill parent, zombie becomes process
						// without parent, orphan. Orphan will be adopted 
						// by INIT, grandparent. In init, you can use
						// wait(); syscall which will release pid.
			printf("child complete");
			exit(0);
			printf("hello"); // Will not print
		}
}