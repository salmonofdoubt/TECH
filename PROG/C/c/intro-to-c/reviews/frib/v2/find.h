/* SRE-U CO2 C Programming - Assignment exam
 * Author: Rodrigo Ribeiro
 *
 * find.h
 */

#ifndef FIND_H
#define FIND_H 1

#include <dirent.h>
#include <sys/types.h>


/* Enums */
enum flagvalues {
  // leczb: I see you are assigning powers of two.
  //        The idiomatic way to do this is
  //          BY_NAME = (1 << 0),
  //          BY_TYPE = (1 << 1),
  //          BY_UID  = (1 << 2),
  //          ...
	BY_NAME=1,
	BY_TYPE=2,
	BY_UID=4,
	BY_GID=8,
	BY_SIZE=16,
	MAX_DEPTH=32,
};
	

/* Structs and typedefs */
typedef struct findopts {
	int				flags;
	short			max_depth;
	unsigned char	*types;
	uid_t			uid;
	gid_t			gid;
	off_t			min_size;
	char			*name;
} findopts_t;

/* Global variables */


/* Function declaration */
// leczb: This should have the extern qualifier
//        Also, the input variables that you are not going
//        to touch (input only), should have the const qualifier.
void find(char *dirp, findopts_t *fopts);




#endif
