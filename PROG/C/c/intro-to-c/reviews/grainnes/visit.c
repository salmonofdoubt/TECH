#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define CHUNKSIZE 10000//4024
#define MAXNAMESIZE 256

/* attempt to get a recursive directory scan working  */
visit(const char *directory) {
    struct dirent **namelist;
    int numdir;
    int buffsize = CHUNKSIZE;

    char *nextdir;
    char *avoid = ".";
    char *alsoavoid = "..";

    // leczb: That's a considerable buffer size ;)
    //        ...but you don't have to this.
    //        You cancalculate the required size on the fly instead
    //        using strlen() inside the while loop, then malloc(),
    //        use it, then free() it.
    //        Note: in this version you have a memory leak: you always
    //              call malloc(), but you never call free().
    nextdir = (char *) malloc(buffsize * MAXNAMESIZE);

    numdir = scandir(directory, &namelist, NULL, alphasort);
    if (numdir < 0) {
        perror("scandir failed");
    }
    else {
        while (numdir--) {
            printf("%s/%s\n",directory,namelist[numdir] -> d_name);
            if (namelist[numdir] -> d_type == DT_DIR) {  // recursive part
            if ( strcmp( (namelist[numdir] -> d_name), avoid) == 0)
                continue;
            if ( strcmp( (namelist[numdir] -> d_name), alsoavoid) == 0)
                continue;

              strcpy(nextdir , directory);
              strcat(nextdir , "/");
              strcat(nextdir , namelist[numdir] -> d_name);
              printf("it's a dir called%s\n",nextdir);
              visit(nextdir);
            }
        }
        free(namelist[numdir]);
    }
    // leczb: I think it's incorrect: if scandir() fails, namelist is going
    //        to be a NULL pointer, so this will result a in a segfault.
    free(namelist);
}
