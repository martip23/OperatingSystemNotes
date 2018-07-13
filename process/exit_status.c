/* This program is to get hold of a child's exit status */

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

main()
{
  pid_t pid;
  int status, exit_status;

  if ((pid = fork()) < 0)
    perror("fork failed");

  if (pid ==0)
    {
      sleep(4);
      exit(5);
    }
 
  /* getting this far means this is the parent. 
     The return value of wait() is the pid of the child.
     The vaule returned to the parent via exit is stored in the high-order
     eight bits of the integer status. */

  if ((pid = wait(&status)) == -1)
    {
      perror("wait failed");
      exit(2);
    }

  /* test to see how the child died.
     The macro WIFEXITED tests to see if this is in fact the case.
     If it returns 0 then it means that the child was stopped by another
     process using a signal 
     
     exit (status)  High byte: status   Low byte: 0  // normal case
     killed by signal  High byte: 0  Low byte: signal
     stopped (job control) High byte: signal  Low byte: 0177

     #define _LOW(v)   (  (v) & 0377)
     #define _HIGH(v)   (  ((v) >>8) & 0377)

     #define WIFEXITED(s)  (_LOW(s) == 0) // normal exit from 0 to 255
     #define WEXITSTATUS(s) (_HIGH(s))  // exit status
   */

  if (WIFEXITED(status))
    {
      exit_status = WEXITSTATUS(status);
      printf("Exit status from %d was %d \n", pid, exit_status);
    }
  
  exit(0);
}


/* Output:
   (After 4 seconds)
   Exit status from 4414 was 5
*/
