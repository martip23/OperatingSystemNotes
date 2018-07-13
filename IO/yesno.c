/* yesno -- get yes or no response from user */

#include <stdio.h>
#include <ctype.h>

#define YES 1
#define NO 0
#define ANSWSZ 80

static char *pdefault = "Type 'y' for YES, 'n' for NO";
static char *error = "Unexpected response";

int yesno(char *prompt)
{
 char buf[ANSWSZ], *p_use, *p;
 
 // if prompt not NULL use it. Otherwise use pdefaults
 p_use = (prompt != NULL) ? prompt: pdefault;
 
 // loop until correct response
 
 for (;;)
 {
  // print prompt
  printf("%s > ", p_use);
  
  if (fgets(buf, ANSWSZ, stdin) == NULL)
      return EOF;
     
  // strip leading white space
  for (p=buf; isspace(*p); p++) ;
  
  switch(*p) {
     case 'Y':
     case 'y':
           return (YES);
     case 'N':
     case 'n':
           return (NO);
     default:
           printf("\n%s\n", error);
           }
   }
 }
 
 main()
 {
  char *p = NULL;
  
  yesno(p);
  
  return 0;
 }
