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

// leczb: Minor style comment: s/resolvetype/resolve_type/
unsigned char *resolvetype(char *param);
// leczb: Minor style comment: s/resolvepwd/resolve_username/
uid_t resolvepwd(char *param);
// leczb: Minor style comment: s/resolvegrp/resolve_groupname/
gid_t resolvegrp(char *param);

#endif
