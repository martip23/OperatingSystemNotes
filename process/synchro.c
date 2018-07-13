/* example for kill, the parent and child processes send each other 
signals SIGUSR1  */
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int ntimes = 0;

main()
{
 pid_t pid, ppid;
 void p_action(int), c_action(int);
 static struct sigaction pact, cact;
 
 // set SIGUSR1 action for parent
 pact.sa_handler = p_action;
 sigaction(SIGUSR1, &pact, NULL);
 
 switch(pid = fork()) {
 case -1: // error
      perror("synchro");
      exit(1);
 case 0: // child
       // set action for child
       cact.sa_handler = c_action;
       sigaction(SIGUSR1, &cact, NULL);
       
       // get parent process-id
       ppid = getppid();
       
       for (;;)
       {
        sleep(1);
        kill(ppid, SIGUSR1); // Send signal to process
        pause();
        }
       // never exits
 default: // parent
       for(;;)
       {
        pause();
        sleep(1);
        kill(pid, SIGUSR1);
        }
        // never exits
  }
}

void p_action(int sig)
{
 printf("Parent caught signal #%d\n", ++ntimes);
}
 
void c_action(int sig)
{
 printf("Child caught signal #%d\n", ++ntimes);
} 
