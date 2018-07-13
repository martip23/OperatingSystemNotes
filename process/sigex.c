/* Example 1: This program shows how sigaction works 
SIGINT generated by key stroke DEL
SIGQUIT generated by Ctrl-\ */
#include <unistd.h>
#include <signal.h>

main()
{
	// sigaction has an sa_handler field, whichis most important.
 static struct sigaction act;
 
 // declare catchint, later to be used as the handler 
 void catchint(int);
 
 // set up the action to be taken on receipt of SIGINT
 act.sa_handler= catchint;
 
 // create a full mask
 sigfillset(&(act.sa_mask));
   
 // before sigaction call, SIGINT will terminate process (default)
 
 sigaction(SIGINT, &act, NULL);
 
 // on receipt of SIGINT control will be passed to catchint
 
 printf("sleep call #1\n");
 sleep(1);
 printf("sleep call #2\n");
 sleep(1);
 printf("sleep call #3\n");
 sleep(1);
 printf("sleep call #4\n");
 sleep(1);
 
 printf("Exiting \n");
 exit(0);
 }
 
 // trivial function to handle SIGINT
 void catchint(int signo)
 {
  printf("\nCATCHINT: signo=%d\n", signo);
  printf("CATCHINT: returning\n\n");
  }


/* Example 2: ignoring SIGINT
replace 
   act.sa_handler = catchint;
with
   act.sa_handler = SIG_IGN;
   **** SIG_IGN = Ignore ****
   
Later it can be enalbed again with:
   act.sa_handler = SIG_DFL;
   sigaction(SIGINT, &act, NULL);
   
It is possible to ignore several signals simultaneously.
   act.sa_handler = SIG_IGN;
   sigaction(SIGINT, &act, NULL);
   sigaction(SIGQUIT, &act, NULL);
*/

/* Example 3: restoring a previous action
   #include <signal.h>
   
   static struct sigaction act, oact;
   
   // save the old action for SIGTERM
   sigaction(SIGTERM, NULL, &oact);
   
   // set new action for SIGTERM
   act.sa_handler = SIG_IGN;
   sigaction(SIGTERM, &act, NULL);
   
   // do the work here
   
   // now restore the old action
   sigaction(SIGTERM, &oact, NULL);
   
*/
