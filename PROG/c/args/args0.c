#include <stdio.h>

// ust echos command-line arguments; ver 0 

main(int argc, char *argv[]){               //argv as array of arg pointers
  
  int i;
  
  for (i = 1; i < argc; i++)                //depending on args given
  printf("%s %s", *++argv, (argc > 1) ? "" : ""); 
 //incrementing it by 1 (++argv) makes it point at the original argv[1] instead of argv[0].
  printf("\n");
  return 0;
}



