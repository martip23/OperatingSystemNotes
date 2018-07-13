/* This program demonstrates the use of sigprocmask */
#include <unistd.h>
#include <signal.h>

main()
{
 static struct sigaction act;
 sigset_t set1, set2;
 int i;
 
 void catchint(int);

 act.sa_handler = catchint;
  
 // completely fill the signal set
 sigfillset(&set1);
 
 // create a signal set which does not include SIGINT and SIGQUIT
 sigfillset(&set2);
 sigdelset(&set2, SIGINT);
 sigdelset(&set2, SIGQUIT);
 
 // set the block
 sigprocmask(SIG_SETMASK, &set1, NULL);
 
 // perform extremely critical code ...

 // set less of a block
 sigprocmask(SIG_UNBLOCK, &set2, NULL);
 
 // perform less critical code ...

 // remove all signal blocks
 sigprocmask(SIG_UNBLOCK, &set1, NULL);

 }
 
