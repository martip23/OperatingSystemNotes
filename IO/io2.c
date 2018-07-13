/* io2 -- copy stdin to stout */
#include <stdio.h>

main()
{
 int c;
 
 while ((c = getchar())!= EOF)
     putchar(c);
}
