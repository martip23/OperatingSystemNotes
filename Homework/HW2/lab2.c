/*			Lab 2 - Patrick Martinez 		*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
char *path, *argv[20], buf[80], n, *p;

int m, status, inword, continu;

while(1) {

inword = 0;

p = buf;

m = 0;

continu=0;

printf( "\nshhh> ");

while ( ( n = getchar() ) != '\n'  || continu ) {
	if ( n ==  ' ' ) { 
	    if ( inword ) {
		inword = 0;
		*p++ = 0;
	    } 
	} else if ( n == '\n' ) {
		continu = 0;
	} else if ( n == '\\' && !inword ) {
		continu = 1;
	} else {
	    if ( !inword ) {
		 inword = 1;
		 argv[m++] = p;
		 *p++ = n;
	     }
	     else 
		 *p++ = n;
	}
}	

char *firstArgs[20];
*p++ = 0;
argv[m] = NULL;

int inRedirect = 0, pipeCount = 0, outRedirect = 0;
int pipeLocation[20];

int j = 0; // Keeps track of final argument

// Get redirect and pipe counts
for (int i = 0; i < m; i++) {
	int k = 0; // For pipe locations
	if (*argv[i] == '<') {
		inRedirect = 1;
	} else if (*argv[i] == '|') {
		pipeCount++;
		pipeLocation[k++] = i;
	} else if (*argv[i] == '>') {
		outRedirect = 1;
	} else {
		if (!inRedirect && !pipeCount && !outRedirect) {
			firstArgs[i] = argv[i];
			j = i; j++;
			printf("Copied:%s\n", firstArgs[i] );
		}
	}
}
firstArgs[j] = NULL;

printf("IR: %d PC: %d OR: %d\n",inRedirect,pipeCount,outRedirect);

int pid = fork();

if (pid < 0)
	printf("ERROR: Fork not created line 76\n");

// Child
else if (pid == 0) {

	// Perform input redirect
	if (inRedirect) {
		int i = 0, irIndex;
		int file;
		// Get index of '<', get filename & redirect input.
		while (*argv[i] != '<') 
			i++;
		irIndex = ++i;
		printf("ReadFrom: %s\n", argv[irIndex]);
		if ((file = open(argv[irIndex], O_RDONLY, 0777)) < 0)
			printf("ERROR: Could not open file\n");
		close(0);
		dup(file);
		close(file);

		inRedirect = 0;
	} 

	// PIPE
	if (pipeCount > 0) {
		int fd[2];

		for (int j = 0; j < pipeCount; j++) {
			pipe(fd);
			int pid2 = fork();

			if (pid2 < 0)
				printf("FORK IN PIPE NOT CREATED\n");

			// Have parent write to pipe
			else if (pid2 > 0) {
				printf("Closing output for pid2:%d\n", pid2);
				close (1);
				dup(fd[1]);
				close(fd[1]);
				close(fd[0]);

			}
			// Make child read from pipe and run command
			else {
				close (0);
				dup(fd[0]);
				close(fd[0]);
				close(fd[1]);
//				printf("Executing child pipe; PID1:%d PID:%d\n", pid, pid2);

				// Get instructions after pipe
				for (int k = pipeLocation[j] + 1, i = 0; k < 20; k++){
					if ((*argv[k] != '<') && (*argv[k] != '>') 
						&& (*argv[k] != '|')) {
						firstArgs[i] = argv[k];
						printf("Copied into child:%s\n", firstArgs[i]);
						i++;
					}
					else {
						firstArgs[i] = NULL;
						break;
					}
				}
			}
		}
	}

	// Perform output redirect
	if (outRedirect) {
		int i = 0, orIndex;
		int file;

		while (*argv[i] != '>')
			i++;
		orIndex = ++i;
		printf("WriteTo: %s\n", argv[orIndex]);
		if ((file = open(argv[orIndex], O_WRONLY, 0777)) < 0)
			printf("ERROR: COULD NOT WRITE TO FILE\n");
		close(1);
		dup(file);
		close(file);

		outRedirect = 0;
	}

printf("Running arg:%s\n", firstArgs[0]);

execvp( firstArgs[0], firstArgs );

} else if (pid > 0) {
	wait(NULL);
}

if ( strcmp(argv[0],"quit") == 0 ) exit (0);

wait(&status);
}
return 0;
}

