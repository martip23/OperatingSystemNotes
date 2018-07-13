#include <stdio.h>

/* copy file f1 to f2 using Standard I/O */

int copyfile(const char *f1, const char *f2)
{
 FILE *inf, *outf;
 int c;
 
 if ((inf = fopen(f1, "r")) == NULL)
      return (-1);
      
 if ((outf = fopen(f2, "w")) == NULL)
 {
   fclose(inf);
   return (-2);
 }
 
 while ((c = getc(inf))!=EOF)
     putc(c, outf);
 
 fclose(inf);
 fclose(outf);
 return (0);
 }
 
 main()
 {
  char f1[30], f2[30];
  
  printf("Please enter file name to copy>");
  scanf("%s", f1);
  
  printf("\nPlease enter dest file name>");
  scanf("%s", f2);
  
  copyfile(f1, f2);
  
  return 0;
 }