//write new file

#include <stdio.h>
#include <stdlib.h>

int main() { 
  FILE *file; 
  file = fopen("sreufile2.txt","w"); 
  //if new file, starts at BOF a file or create a file if it does not exist.
  fprintf(file,"%s","Some initial text. Some initial text."); 
  fseek  (file, 10, SEEK_SET );
  //scans to position
  fprintf(file,"%s", "+ +++ searchstring +++ +" , 50, 1, file );
  
  fclose (file);
  getchar(); 
  // let it write 
  return 0; 
}

