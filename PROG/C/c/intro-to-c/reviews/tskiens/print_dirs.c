/* file : print_dirs.c */
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "print_dirs.h"

// leczb: Design comment: I would have kept this function in main.c as
//        print_dirs.c should be only concerned with the core job.
//        Printing the usage is something auxiliary.
/* invaliud usage */
int print_usage(char *my_progname){
  printf("Usage: %s -d <path>\n", my_progname);
  exit(EXIT_FAILURE);
}

/* filter out the dot dirs */
int not_dot(const void *input) {
  // leczb: Nice and short. Very idiomatic ;)
  return ((strcmp(input, ".") && strcmp(input, "..")));
}

/* open a dir and print contents */
void print_dir(char *p) {
  DIR           *dirp ;
  struct dirent *entry ;
  // leczb: Major bug: allocating a fixed sized buffer and then using sprintf()
  //        on it is not safe. This is a very common source of security
  //        vulnerabilities. See http://en.wikipedia.org/wiki/Buffer_overflow
  //        for the details.
  //        You either have to use snprintf() (passing in the number of available
  //        bytes in the buffer) or malloc() the buffer after calculating the
  //        required size using strlen().
  //
  //        Minor comment: there's no point in intializing the array to zeroes
  //        if you are going to s(n)printf() into it as that's going to
  //        overwrite it anyway.
  //        The initialization is extra work the CPU has to do.
  char           sbuff[4096] = {0};
  // leczb: Goog call using size_t for this variable! Many people used a
  //        straight "int", which is not wide enough.
  size_t         plen = 0;


  // leczb: You are opening the dir, but you are not closing it anywhere.
  //        This is a filedescriptor leak. Try to set your
  //        filedescriptor limit to something ridiculosly low
  //        and try to run your program against a deep directory
  //        structure to see what happens:
  //          bash # start a new shell, so ulimit only applies to that
  //          mkdir -p /tmp/1/2/3/4/5/6/7/8/9/10/11
  //          ulimit -n 10
  //          ./find /tmp/1
  dirp = opendir(p) ;
  if (dirp == NULL) {
    perror("opendir");
    // leczb: Minor style comment: if you add a "return" here, then you don't
    //        need an "else" branch, which means, that the code below doesn't
    //        have to be indented. Improves readability.
  }
  else {
    while((entry = readdir(dirp)) != NULL) {  /* cycle through entries in a dir */
      // leczb: You are not using this variable for anything.
      plen  = strlen(entry->d_name);

      if(not_dot(entry->d_name)) {            /* filter out dot_dirs */
        sprintf(sbuff, "%s/%s", p, entry->d_name);

        // leczb: Minor: you are doing the exact same printf() in both the if
        //        and the else branches. You can move it before the if(), so
        //        you have only one instance of it.
        //
        //        Something else: you are using a "magic number". 0x4 is a
        //        platform-dependent value. You should use the symbolic name
        //        DT_DIR (see the NOTES section in man 3 readdir).
        if( (entry->d_type == 0x4)) {
          printf("%s/%s\n", p, entry->d_name);
          print_dir(sbuff);                   /* recursive call of print_dir */
        }
        else{
          printf("%s/%s\n", p, entry->d_name);
        }
      }
    }
  }
}
