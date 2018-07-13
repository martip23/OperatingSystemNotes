#include <stdio.h>
#include <fcntl.h>

// for isspace and isalnum definitions
#include <ctype.h>

#define MAXTOK 256

static char inbuf[MAXTOK+1];

char *getword(FILE *inf)
{
 int c, count = 0;
 
 // strip white space
 do {
     c = getc(inf);
    } while (isspace(c));
    
 if (c == EOF)
     return (NULL);
     
 if (!isalnum(c)) // is character non-alphanumeric
       inbuf[count++] = c;
 else
 {
     // assemble "word"
     do {
          if (count < MAXTOK)
              inbuf[count++] = c;
           
          c = getc(inf);
        }while (isalnum(c));
        ungetc(c, inf); // push back character
 }
 
 inbuf[count] = '\0'; // make sure string returned
 return (inbuf);
}

main()
{
 char filename[30];
 FILE *fp;
 char *p;
 
 printf("Please enter the file name>");
 scanf("%s", filename);
 
 fp = fopen(filename, "r");
 p=getword(fp);
 printf("%s\n", p);
 
 return 0;
}
