/* SRE-U CO2 C Programming - Project Exam
 * Author: Rodrigo Ribeiro
 *
 * Implement a simple "find" program
 * Implement a simple "find" program, similar to the one described in man 1 find
 * Initial version (required):
 * just takes a single path argument and prints the filenames under that path, recursively (like find does, when called with no filtering arguments)
 * if called without arguments, it assumes "." was passed in (the current directory, that is)
 * Once the initial version works:
 * First: SAVE IT, then:
 * Add support for options for filtering filenames (implement at least two of these):
 * -n <name>
 *
 *
 *  Only print filenames that match <name>
 *  Use exact match of directory entry name, not the full path.
 *
 *
 *  Only do globbing or regexp support if you are bored and you have a basic full-match version working (and copied under a different name). Only for bonus points.
 *  Hint: this can be implemented without resorting to stat()ing the file
 *  -t <type>
 *
 *
 *  Only print filenames of files that have the exact file type:
 *  'l' = symbolic link
 *  'd' = directory
 *  'f' = normal file
 *
 *
 *  'c' = character device
 *  'b' = block device
 *  's' = socket
 *  Hint: this can be implemented without resorting to stat()ing the file 
 *  -o <uid>
 *
 *
 *  <uid>: numeric owner id
 *  Only print filenames of files owned by the given user.
 *  -g <gid>
 *
 *
 *  <gid>: numeric group id
 *  Only print filenames of files owned by the given group.
 *  -s <size>
 *
 *
 *  <size>: numeric file size in bytes
 *  Only print files that are at least this big. (Apparent file size - the same thing as returned by ls -l. Not the real storage size.)
 *  And if you are really bored,
 *  -d <max depth>
 *
 *
 *  Maximum recursion depth (don't go into directories deeper than this).
 *  Required:
 *  Separate the project into multiple .c files and provide header files (with #ifndef guard)
 *  Provide a Makefile that compiles your binary executable by default and also has a "clean" target
 *  Use getopt() for parsing the flags
 *  Style: "readable" code
 *  sensible variable and function names
 *  comments where you are doing something nontrivial
 *  correct indentation
 *  spaces around pointers
 *  Rules:
 *  Looking at manpages: OK
 *  Looking up things on Google: OK
 *  Asking questions from the instructor: OK
 *  Chatting to others: NOT OK
 *  Copying code as-is: NOT OK (exception: man page examples)
 *  When you are ready, your source files and Makefile have to be copied to /home/leczb/projects/intro-to-c/exam/$USER
 *  Deadline: today, 6pm local time (write access will be revoked at the deadline)
 *  Only the contents in the directory above are going to be evaluated
 *  You can copy multiple versions in there. You are highly encouraged to snapshot your project here, any time it works ;)
 *  If you have a working implementation of the "Initial version", it's a pass
*  Hints:
*  The filesystem is a recursive data structure - recursive functions are the natural way for descending into a directory tree
*  Don't forget to filter out the dotdirs (the "." and ".." entries present in every directory)
*  Only descend into directories - don't follow symbolic links
*  Filtering options (-n, -t, etc.) should only control what's printed. You still have to descend into every directory, even the ones that were not printed.
*  It's OK to use global variables to save the option values (we are not trying to implement a thread-safe library)
*  Don't forget to include what the SYNOPSIS section says in the man page
*  If gcc prints anything with the "-Wall" flag, you are doing something wrong
*  Only do type-casts if you know what your are doing; if you have to put it there to make a compiler warning go away - it's most probably wrong!
*  It's OK to base your code on examples found in the man pages
*  Standard library functions you'll might need (at least my reference implementation uses these):
		*  malloc
		   *  free
		   *  scandir, alphasort (a filter function is not applicable here as you want all entries and you will decide later to print them or not)
		   *  strcat
		   *  strcpy
		   *  strcmp, strncmp
		   *  strlen
		   *  printf
		   *  perror
		   *  getopt
		   *  atoi
		   *  Syscalls you'll might need:
		   *  chdir
		   *  stat
 */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "find.h"

int isdir(const struct dirent *entry){
		return entry->d_type == DT_DIR;
}


void find(char *dirp, findopts_t *fopts){
	static size_t depth = 0;	// current depth
	short l_dirp;				// length of the current dirp
	struct dirent **contents;	// pointers to all contents on dirp
	int ncontents;				// number of pointer entries declared abve
	int i;						// iterator

	depth++;
	if ( (fopts->flags & MAX_DEPTH) && depth > fopts->max_depth){
			depth--;
			return;
	}

	l_dirp = strlen(dirp);		// length of the current dirp
	ncontents = scandir(dirp, &contents, NULL, NULL);
	
	for (i=0; i < ncontents; i++){
		// Skip "." and ".."
		if (! (strcmp(contents[i]->d_name, ".") && strcmp(contents[i]->d_name, "..")) ){
			continue;
		}

		printf("%s/%s\n", dirp, contents[i]->d_name);

		if ( isdir(contents[i]) ) {
			char *subdirp;
			subdirp = (char *) malloc(l_dirp+contents[i]->d_reclen+2);
			strcpy(subdirp, dirp);
			strcat(subdirp, "/");
			strcat(subdirp, contents[i]->d_name);
			find(subdirp, fopts);
		}

		free(contents[i]);
	}

	if (ncontents > 0)
		free(contents);

	depth--;
	return;
}
