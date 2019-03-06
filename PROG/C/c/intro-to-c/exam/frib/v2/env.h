/* SRE-U C02 C Programming
 * Author: Rodr
 * Resolves user and group ids
 *
 * getent.h
 */


#ifndef GETENT_H
#define GETENT_H 1

#include <dirent.h>
#include <sys/types.h>

unsigned char *resolvetype(char *param);
uid_t resolvepwd(char *param);
gid_t resolvegrp(char *param);

#endif
