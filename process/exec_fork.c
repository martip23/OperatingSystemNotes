#include <sys/types.h>
#include <unistd.h>

main()
{
  pid_t pid;

  switch(pid = fork()) {
  case -1: perror("fork failed");
           break;

  case 0: execl("/bin/ls", "ls", "-l", (char *)0);
          perror("exec failed");
          break;

  default: // parent uses wait to suspend execution until child finishes
          wait((int *)0);
          printf("ls completed\n");
          exit(0);
  }
}
         
