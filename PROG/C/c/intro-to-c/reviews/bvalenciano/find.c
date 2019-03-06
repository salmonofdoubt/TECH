#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <features.h>

// leczb: You should always include the corresponding header file to make
//        sure your advertised signatures match the actual implementation.
//        Otherwise, the compiler won't notice any mistake.
//
//          #include "find.h"

// leczb: It's best practice to declare input-only arguments as const, so the
//        compiler can warn if you try to write to them by mistake.
//        So
//          int open_directory(const char *path) {
int open_directory (char *path){
  struct dirent **dirent;
  struct stat *statp;
  char *path_aux;
  int num;

  // leczb: It's easier to just declare a struct stat variable:
  //          struct stat stat_result;
  //        This way, you don't have to manually malloc() and you don't have
  //        to worry about free()ing it later, as it lives on the stack,
  //        so when you return from your function, it is freed up automatically.
  statp =malloc (sizeof(struct stat));
  // leczb: Why subtract one from the return value of scandir?
  num = scandir(path, &dirent, 0, alphasort)-1;
  if (num < 0) perror("scandir");
  else {
    // leczb: This looks odd. A more idiomatic way of iterating the results
    //        would be:
    //          for (i = 0; i < num; i++) {
    //            ... dirent[num] ...
    while (num >= 0) {
      // leczb: This is going to skip any filename that begins with ".".
      //        I'm pretty sure that's not what you wanted.
      if (dirent[num] -> d_name[0]== '.'){
        num --;
        continue;
      }
      // leczb: An error message should be printed before exiting with
      //        EXIT_FAILURE to let the user know what went wrong.
      //        But kudos for checking the return value from malloc().
      //        Not everyone did it.
      if ((path_aux = malloc (strlen(dirent[num]->d_name) + strlen(path)+2)) == NULL) exit(EXIT_FAILURE);          
      strcpy(path_aux, path);
      strcat(path_aux, "/");
      strcat(path_aux, dirent[num] ->d_name);
      stat (path_aux, statp);
      // leczb: This is correct, but the portable way to do this is to use the
      //        POSIX macros described on man 2 stat. S_ISDIR(statp->st_mode) in
      //        this case.
      if ((statp ->st_mode & S_IFMT) == S_IFDIR){
        printf ("%s\n", path_aux);
        // leczb: Correct way to do the recursion. Nicely done! :)
        open_directory(path_aux);
      }
      else{
        printf ("%s\n", path_aux);
        // leczb: You have a memory leak here: you are only freeing these areas
        //        in the else branch of the if statement.
        free(dirent[num]);
        free(path_aux);
      }
      // leczb: Style: there should be no space between varname and postfix operator.
      num --;
    }
    // leczb: Style: wrong indentation. The following line should be indented as
    //        this line
  free(dirent);
  }
  // leczb: You have a memory leak here: you are not free()ing statp that you
  //        have malloc()'d above.
  return 1;
}
