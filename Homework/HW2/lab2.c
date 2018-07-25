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

*p++ = 0;

argv[m] = 0;

//printf("Argv[0] = %s\n", argv[0]);
for (int i = 0; i < (m-1); i++) {
	printf("i=%d\n", i);
	printf("m=%d\n", m);
	char *argvp[20];
	printf("%s\n", argv[i]);
	// if((strcmp(argv[i], "|") != 0) && ((strcmp(argv[i],"<") != 0)) 
	// 	&& (strcmp(argv[i], ">") != 0)) {
	// 	strcpy(argvp[i], argv[i]);
	// 	printf("STRCPY CALLED\n");
	// }
	if (strcmp(argv[i], "|") == 0){
		char *argvc[20];
		printf("i=%d\n", i);

		for (int j = (i + 1), c = 0; j < m; j++) {
			printf("c=%d\n", c);
			printf("j=%d\n", j);
			strcpy(argvc[c], argv[j]);
			c++;
		}
 
		int pid;
		int fd[2];

		printf("%s\n", "Making pipe");
		if (pipe(fd) == -1)
			printf("Pipe not created");

		pid = fork();

		if (pid < 0)
			printf("Child not created");

		/**
		Set parent to push to pipe
		**/
		else if (pid > 0) {
			close(1);
			dup(fd[1]);
			close(fd[1]);
			close(fd[0]);
		}
		/**
		Set child to read from pipe and run
		**/
		else {
			close(0);
			dup(fd[0]);
			close(fd[0]);
			close(fd[1]);

			wait(NULL);

			if(execvp(argvc[0], argvc) == -1)
				printf("Error with child pipe\n");
		}
	}
	printf("OUT OF FOR\n");
}
printf("Out Of Loop\n");

if ( strcmp(argv[0],"quit") == 0 ) exit (0);

if ( fork() == 0 )

 	{
// 	printf("PID: %d\n", getpid());
	execvp( argv[0], argv );
	printf ( " didn't exec \n ");
	}

wait(&status);

}
return 0;
}

