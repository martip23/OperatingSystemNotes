/*			Lab 2 - Patrick Martinez 		*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
char *path, *argv[20], buf[80], n, *p;

int m, status, inword, continu;
int pid = -1;
int pid2 = -1;

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

	}	
	else if ( n == '<') {
		printf("< DETECTED\n");




	} else if ( n == '|') {
		printf("| DETECTED\n");
		int pid;
		int fd[2];
		
		// Create pipe
		if (pipe(fd) == -1)
			printf("ERROR! PIPE NOT CREATED for some reason");

		// Create child
		pid = fork();

		if (pid < 0)
		{
			printf("ERROR! Child not created for some reason\n");
		}

		// Child create grandchild
		else if (pid == 0) {
			pid2 = fork();
			wait(NULL);

			// Child read from pipe
			if (pid2 > 0) {
				close(0);
				dup(fd[0]);
				close(fd[0]);
				close(fd[1]);

				m = 0;
				*p++;

				wait(NULL);

			}
			// Grandchild write to pipe
			else if (pid2 == 0) {
				close(1);
				dup(fd[1]);
				close(fd[1]);
				close(fd[0]);				

				break;
			}
		} else break;

	} else if ( n == '>') {
		printf("> DETECTED\n");
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

*p++ = 0;

argv[m] = 0;

//printf("Argv[0] = %s\n", argv[0]);

if ( strcmp(argv[0],"quit") == 0 ) exit (0);

if (pid == 0 || pid2 == 0) {
//	printf("PID(CH): %d\n", getpid());
 	execvp( argv[0], argv);
 	printf("Didn't exec\n");
} else if ( fork() == 0 )

 	{
// 	printf("PID: %d\n", getpid());
	execvp( argv[0], argv );
	printf ( " didn't exec \n ");
	}

wait(&status);

}
return 0;
}

