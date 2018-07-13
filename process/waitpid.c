/* This program is to obtain a child's exit status using waitpid */

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
      printf("Child %d sleeping ...\n", getpid());
      sleep(4);
      exit(5);
    }

	// waitpid() returns the process ID of the child which exited,
	//or zero if WNOHANG was used and no child was available, or -1 on error
	// WNOHANG: means to return immediately if no child has exited.
  while(waitpid(pid, &status, WNOHANG) == 0)
      {
          printf("Still waiting...\n");
          sleep(1);
      }

  if (WIFEXITED(status))
        {
         exit_status = WEXITSTATUS(status);
         printf("Exit status from %d was %d \n", pid, exit_status);
        }

  exit(0);
}
