/* printf demonstration 
int printf(const char *fmt, arg1, arg2, ...argn);

Conversion:
%d standard conversion for a signed integer.
%u unsigned int, to be printed in decimal form.
%O integer, to be printed in unsigned octal form.
%x integer, to be printed in unsigned hexadecimal form. The characters a,b,c,d,e,f will be used 
   for the additional hexadecimal digits. If the specification %X is given, then A,B,C,D,E,F will
   be substituted.
%ld long, signed integer, to be printed in decimal form.
%f float or double, to be printed in standard decimal form.
%c char, to be output exactly as it is.
%s string.

Width and precision:
%10.5d print the corresponding int argument in a field 10 characters wide;
       if the argument has fewer than five digits, pad it with leading zeros.
%.5f   print the corresponding float or double argument with five decimal places.
%10s   print the corresponding string in a field which is a minimum of 10 characters 
       in length.
%-30s  the corresponding string argument will be printed on the left-hand side of a field
       at least 30 characters across.
*/

#include <stdio.h>
#include <math.h>

main()
{
 char *weekday = "Sunday";
 char *month = "September";
 char *string = "Hello, world";
 
 int i = 11058;
 int day = 15, hour = 16, minute = 25;
 
 // print a date
 printf("Date is %s, %d, %s, %d:%.2d\n", weekday, day, month, hour, minute);
 
 // print newline again
 putchar('\n');
 
 // show width, precision interaction for string
 printf(">>%s<<\n", string);
 printf(">>%30s<<\n", string);
 printf(">>%-30s<<\n", string);
 printf(">>%30.5s<<\n", string);
 printf(">>%-30.5s<<\n", string);
 
 putchar('\n');
 
 // print i in variety of styles
 printf("%d, %u, %o, %x, %X\n", i, i, i, i, i);
 
 // print pi to 5 decimal places
 printf("PI is %.5f\n", 4*atan(1.0));
 }
 
 
 /* output:
 Date is Sunday, 15, September, 16:25
 
 >>Hello, world<<
 >>                  Hello, world<<
 >>Hello, world                  <<
 >>                         Hello<<
 >>Hello                         <<
 
 11058, 11058, 25462, 2b32, 2B32
 PI is 3.14159
 */