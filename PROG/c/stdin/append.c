#include <stdio.h>
int main()
{
    FILE *fp
    file = fopen("text.txt","a");
    fprintf(fp,"%s","This is just an example :)");
    //appends some text
    fclose(fp);
    return 0;
}