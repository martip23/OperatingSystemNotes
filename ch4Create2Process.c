#include <stdio.h>


/**
This code demonstrates the creation of two processes. 
When a child is created, it has a PID of 0 in reference
to itself.
**/
void main (int argc, char* argv[])
{
	int pid;
	pid = fork();
	if (argv[0] == q) { // Queue
		// CODE FOR P -> C -> GC
	}
	else if (argv[1] == s) {// Sibling
		// CODE FOR P -> C1 , C2
		
		pid1 = fork(); // Child process
		if (pid1 > 0) // This will be executed by parent
		{
			pid2 = fork(); // Grandchild Process
			if (pid2 > 0) {
				// Ran by parent
			}
			if (pid2 == 0) {
				// Ran by child 2
			}
			else {
				// ERROR
			}
		}
		else if (pid1 == 0) {
			// This will be executed by child1
		}
		else {
			// Error
		}
		
	}
}