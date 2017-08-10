/* SRE-U C02 C Programming
 * Author: Rodrigo Ribeiro
 * Resolves user and group ids
 *
 * getent.c
 */

#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "env.h"


mode_t resolvetype(char *param){
	mode_t mode = 0;
	int i;

	for (i=0; param[i]!= '\0'; i++){
		switch (param[i]){
			case 's':
				mode = mode | S_IFSOCK;
				break;
			case 'l':
				mode = mode| S_IFLNK;
				break;
			case 'r':
				mode = mode| S_IFREG;
				break;
			case 'b':
				mode = mode| S_IFBLK;
				break;
			case 'd':
				mode = mode| S_IFDIR;
				break;
			case 'c':
				mode = mode| S_IFCHR;
				break;

			default:
				fprintf(stderr, "Requested type %c not supported\n", param[i]);
				break;
		}
	}

	return mode;
}

// TODO Fix resolvepwd to accept numeric uids as argument
uid_t resolvepwd(char *param){
		struct passwd *pwd;

		pwd = getpwnam(param);
		return pwd->pw_uid;
}

// TODO Fix resolvegrp to accept numeric gids as argument
gid_t resolvegrp(char *param){
		struct group *grp;
		
		grp = getgrnam(param);
		return grp->gr_gid;
}
