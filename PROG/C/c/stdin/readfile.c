/* Program to display the contents of a file on screen */
#include <stdio.h>
void main()
{
   FILE *fopen(), *fp;
   int c;
   fp = fopen("text.txt","r");
   c = getc(fp);
   while (c!= EOF){
   	putchar(c);
		c = getc(fp);
   }
   fclose(fp);
}