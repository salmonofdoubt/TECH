#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <features.h>

typedef int (*filter_t)(const struct dirent *);

int filter_type(const struct dirent *dirent){
  // leczb: I don't understand what _BSD_SOURCE is doing here. How did you end
  //        up with this expression?
  switch(dirent ->d_type & _BSD_SOURCE){
    case DT_DIR:
    case DT_LNK:
    case DT_REG:
    case DT_BLK:
    case DT_CHR:
    case DT_SOCK:
      return 1;
      break;
    default:
      return 0;
      // leczb: Style: break is not required in the default case.
      break;

  }
}


void print_filter(char *path_aux, char *name_file, char *type_command, char *name){
  //if(type_command != NULL)
  
  // leczb: Style: if you have multiple conditions, you should chain them
  //        together with &&, instead of nesting if statements.
  //        So this becomes
  //          if (name != NULL && strcmp(...) == 00) {
  //            printf(...)
  //          }
  if (name != NULL)
    if (strcmp(name_file, name)== 0) printf("%s\n", path_aux);
}

int open_directory (char *path, char *type_command, char *name){
  struct dirent **dirent;
  struct stat *statp;
  DIR *dir;
  char *path_aux;
  int num;
  filter_t f;
  // leczb: Same comments apply as in find.c
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
        print_filter(path_aux, dirent[num]->d_name, type_command, name);
        //printf ("%s\n", path_aux);
        open_directory(path_aux, type_command, name);
      }
      else{
        print_filter (path_aux, dirent[num]-> d_name, type_command,name);
        //printf ("%s\n", path_aux);
        free(dirent[num]);
        free(path_aux);
      }
      num --;
    }
  free(dirent);
  }
  return 1;
}

int main (int argc, char **argv){
int opt =0;
char type[2];
char *name;

while ((opt = getopt(argc, argv, "n:t:")) != -1){
  switch(opt){
    case 'n':
      if(optarg == NULL) exit (EXIT_FAILURE);
      else{
        name = malloc(strlen(optarg)+1);
        // leczb: Good call, but actually, there is no need to copy the optarg,
        //        as it's not going to be altered. But it's good practice to
        //        copy it anyway ;)
        strcpy(name, optarg);
      }
      // leczb: Bug: missing break statement.
    case 't':
      if (optarg == NULL) exit (EXIT_FAILURE);
       else{
          strcpy(type,optarg);
        }
        break;
      break;
    default:
      fprintf(stderr, "Usage: %s\n",argv[0]);
      exit (EXIT_FAILURE);  
    }
  }

  // leczb: This should have been argc == 2
  if (argc == 1) open_directory(".",type, name);
  else open_directory(argv[optind], type, name);
  exit(EXIT_SUCCESS);
}
