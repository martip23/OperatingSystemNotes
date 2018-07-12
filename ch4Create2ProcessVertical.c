#include <stdio.h>


/**
This code demonstrates the creation of two processes. 
When a child is created, it has a PID of 0 in reference
to itself. Vertical structure
**/
void main (int argc, char* argv[])
{
	int pid;
	pid = fork();
	if (pid > 0) {
		// Parent section
	}
	else if (pid == 0) {
		pid2 = fork();
		if (pid2 > 0) {
			// Child section
		}
		else if (pid2 == 0) {
			// Run grandchild section
		}
		else { // ERROR
		}
	else { // ERROR
	}
}