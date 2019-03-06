#ifndef PREDICATES_H
#define PREDICATES_H 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Owner user ID to match */
uid_t opt_uid;

/* Group ID to match */
gid_t opt_gid;

/* Filename to match */
char *opt_name;

/* Directory entry type to match */
unsigned char opt_type;

/* Minimum file size in bytes to match */
size_t opt_min_size;


/* Filter function that returns
 *  1 if the owner of the given file matches opt_uid
 *  0 otherwise
 */
extern int pred_uid(const char *path, const struct dirent *entry);

/* Filter function that returns
 *  1 if the group of the given file matches opt_gid
 *  0 otherwise
 */
extern int pred_gid(const char *path, const struct dirent *entry);

/* Filter function that returns
 *  1 if the name of the given file matches opt_name
 *  0 otherwise
 */
extern int pred_name(const char *path, const struct dirent *entry);

/* Filter function that returns
 *  1 if the type of the given file matches opt_type
 *  0 otherwise
 */
extern int pred_type(const char *path, const struct dirent *entry);

/* Filter function that returns
 *  1 if the size of the given file is at larger than or equals to opt_min_size
 *  0 otherwise
 */
extern int pred_min_size(const char *path, const struct dirent *entry);

#endif
