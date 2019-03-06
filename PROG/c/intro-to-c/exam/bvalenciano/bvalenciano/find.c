#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <features.h>

int open_directory (char *path){
  struct dirent **dirent;
  struct stat *statp;
  char *path_aux;
  int num;

  statp =malloc (sizeof(struct stat));
  num = scandir(path, &dirent, 0, alphasort)-1;
  if (num < 0) perror("scandir");
  else {
    while (num >= 0) {
      if (dirent[num] -> d_name[0]== '.'){
        num --;
        continue;
      }
      if ((path_aux = malloc (strlen(dirent[num]->d_name) + strlen(path)+2)) == NULL) exit(EXIT_FAILURE);          
      strcpy(path_aux, path);
      strcat(path_aux, "/");
      strcat(path_aux, dirent[num] ->d_name);
      stat (path_aux, statp);
      if ((statp ->st_mode & S_IFMT) == S_IFDIR){
        printf ("%s\n", path_aux);
        open_directory(path_aux);
      }
      else{
        printf ("%s\n", path_aux);
        free(dirent[num]);
        free(path_aux);
      }
      num --;
    }
  free(dirent);
  }
  return 1;
}

