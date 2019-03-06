//Implement simple grep command
/*
mygrep <searchstring> filename
only print lines that contain the search string
Bonus: support regex
Bonus: implement tac
Bonus: induce a stackoverflow

getchar()       stdin
getc(FILE*) 
fgets()         stdlib
getline()       GNU
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main() { 
  char ss  ;
  char fn  ;
  int c    ;
  
  printf("Enter search string: ")   ;
  scanf("%s", &ss)                  ; 
  printf("Enter filename: ")        ;
  scanf("%s", &fn)                  ;
  //sreufile2.txt 
  FILE *file                        ; 
  file = fopen("fn","r")            ;

  
  int BUFFSIZE = sizeof(file)  ;
  //calc my bufsize fit
  fread(&fn, sizeof(char), BUFFSIZE, file);
  
  // stick my file 
  strstr(file, ss)                 ;
  // compare 'file' with what I have in buffer with ss
  // search buf for word (case sensitive)
  //char *res = strstr(, variable)  ;
  // word found, print file
  
    if(res != NULL)
  
  
    printf("Prints the whole file though: %s\n", *file);                     

  getchar(); 
  // let it close
  fclose(file);
  return 0; 
}