/* PRINT_IT.C -- This program prints a listing 
 * with line numbers added.
 * MS-DOS Application Only
 * Non-ANSI Application */

#include <stdio.h>
#include <stdlib.h>

void do_heading(char *filename);

int line,page;

main(int argv, char *argc[]) {
  char buffer[256];
  FILE *fp;  
  
  if(argv < 2) {
    fprintf(stderr, "\nProper Usage is: ");
    fprintf(stderr, "\n\nPRINT_IT filename.ext\n");    
    exit(1);
  }
  
  if ((fp = fopen(argc[1], "r")) == NULL) {
    fprintf(stderr, "Error opening file, %s!", argc[1]);
    exit(1);
  }
  
  page = 0;
  line = 1;
  do_heading(argc[1]);
  
  while(fgets(buffer, 256, fp) != NULL) {
    if(line % 55 == 0)
      do_heading(argc[1]);
      
    fprintf(stdout, "%4d:\t%s", line++, buffer);
  }
  
  fprintf(stdout, "\f");
  fclose(fp);
  return 0;
}

void do_heading(char *filename) {
  page++;
  
  if (page > 1)
      fprintf(stdout, "\f");
      
  fprintf(stdout, "Page: %d, %s\n\n", page, filename);
}