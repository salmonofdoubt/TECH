/* SRE-U CO2 C Programming - Project exam
 * Author: Rodrigo Ribeiro
 *
 * find.c
 */

#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "find.h"

int isdir(const struct dirent *entry){
		return entry->d_type == DT_DIR;
}

char *pathbuilder(char *dirp, char *filep){
  // leczb: This should be size_t (which is much wider and unsigned as well).
	int f_len;
	char *f;

	f_len = strlen(dirp) + strlen(filep) + 2;
	f = (char *) malloc(f_len);
        // leczb: bug: you are not checking the return value of malloc().
        //        It might be NULL.

        // leczb: Nice and tight - very idiomatic ;)
	return strcat(strcat(strcpy(f, dirp), "/"), filep);
	
}
// sieve can return on the first failed test, but not before all have run
int sieve(char *fname, const struct dirent *entry, findopts_t *fopts){
	struct stat *s;
	int r_stat;

	if (fopts->flags & BY_NAME){
		// strcmp returns 0 on equality
		if ( strcmp(entry->d_name, fopts->name) != 0 )
			return 0;
	}


	if (fopts->flags & BY_TYPE){
		int i;
		for (i=0; fopts->types[i] != '\0'; i++){
			if (fopts->types[i] == entry->d_type)
                                // leczb: goto is considered harmful... but it's
                                //        acceptable here.
                                //        Minor style comment: labels should be 
                                //        all-caps and I would have named it
                                //        TYPE_MATCHED.
				goto type_match;
		}
		return 0;
	}
type_match:

	// Made this far, time to reconstruct the filemane and stat
        // leczb: You could have just declared a struc stat variable instead of
        //        struct stat *, so you don't have to malloc() and free().
	s = (struct stat *) malloc(sizeof(struct stat));
	r_stat = lstat(fname, s);

	if (fopts->flags & BY_UID ){
		// check whether stat succeed and compare username
		if ((r_stat == -1) || (fopts->uid != s->st_uid)){
                  // leczb: Memory leak: you are not free()ing the space you've
                  //        malloc()'d. Applies to all return statements below.
                  //        Recall the goto example where resources were
                  //        allocated and released. This would be a place
                  //        to use that.
			return 0;
		}
	}

	if (fopts->flags & BY_GID){
		// check whether stat succeed and compare group
		if ((r_stat == -1) || (fopts->gid != s->st_gid)){
			return 0;
		}
	}

	if (fopts->flags & BY_SIZE){
		// check whether stat succeed and compare sizes
		if ((r_stat == -1) || (fopts->min_size > s->st_size)){
			return 0;
		}
	}
	
	// Clean pass
	return 1;
}

// leczb: Options nicely collapsed into a single struct. Nicely done!
void find(char *dirp, findopts_t *fopts){
  // leczb: Hmm.. static is evil. I would have used a function argument for
  //        keeping track of the current depth.
  //        I know we didn't deal with multi-threading, but imagine what
  //        would happen if you had this function run in multiple threads.
  //        Mayhem! :)
  //        Also, by having a copy on the stack, you don't have to do the goto +
  //        decrement dance.
	static size_t depth = 0;	// current depth
	short l_dirp;				// length of the current dirp
	struct dirent **contents;	// pointers to all contents on dirp
	int ncontents;				// number of pointer entries declared abve
	int i;						// iterator

	// check current depth and interrupt flow, of limit is imposed
	depth++;
	if ( (fopts->flags & MAX_DEPTH) && depth > fopts->max_depth){
		goto end;
	}

	l_dirp = strlen(dirp);		// length of the current dirp
	ncontents = scandir(dirp, &contents, NULL, NULL);
	
	for (i=0; i < ncontents; i++){
		char *fname;

                // leczb: you could have implemented this as a filter function
                //        for scandir(). Not a big deal. This is a little bit
                //        more performant, but only marginally.
		// Skip "." and ".."
		if (! (strcmp(contents[i]->d_name, ".") && strcmp(contents[i]->d_name, "..")) ){
			continue;
		}

		// reconstructs the path/filename to be used on sieve and recurse down
		fname = pathbuilder(dirp, contents[i]->d_name);

		// pass current entry through a sieve, according to argv
		if ( sieve(fname, contents[i], fopts) ) {
			printf("%s/%s\n", dirp, contents[i]->d_name);
		}


		// if current entry is a directory, recurse down 
		if ( isdir(contents[i]) ) {
			find(fname, fopts);
		}

                // leczb: Nice! You have avoided leaking memory ;)
		free(fname);
		free(contents[i]);
	}

	if (ncontents > 0)
		free(contents);

end:
	depth--;
	return;
}
