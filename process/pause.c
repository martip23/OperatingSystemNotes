/* tell me later program.
A running example
$./a.out 3 hello
tml process-id 19139
(after 3 minutes)
$hello
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0
#define BELLS "\007\007\007" // ASCII bells

int alarm_flag = FALSE;

// routine to handle SIGALRM
void setflag(int sig)
{
 alarm_flag = TRUE;
}

main(int argc, char **argv)
{
 int nsecs, j;
 pid_t pid;
 static struct sigaction act;
 
 if (argc<=2)
 {
  fprintf(stderr, "Usage: tml #minutes message\n");
  exit(1);
 }
 
 if ((nsecs = atoi(argv[1])*60) <=0)
 {
  fprintf(stderr, "tml: invalid time\n");
  exit(2);
  }
  
  // fork to create background process
  switch(pid = fork()) {
  case -1: // error
       perror("tml");
       exit(1);
  case 0:  // child
       break;
  default:
       printf("tml process-id %d\n", pid);
       exit(0);
  }
  
  // set action for alarm
  act.sa_handler = setflag;
  sigaction(SIGALRM, &act, NULL);
  
  // turn on alarm clock
  alarm(nsecs);
  
  // pause until signal ...
  pause();
  
  // if signal was SIGALRM, print message
  if (alarm_flag == TRUE)
  {
   printf(BELLS);
   for (j=2; j<argc; j++)
        printf("%s ", argv[j]);
   printf("\n");
  }
  
  exit(0);
 } 
   
