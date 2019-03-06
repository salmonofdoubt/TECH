/* SRE-U C02 C Programming - Project exam
 * Author: Rodrigo Ribeiro
 *
 * getent.c
 */

#include <ctype.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "env.h"


unsigned char *resolvetype(char *param){
	unsigned char *types;
	int i;

	types = (unsigned char *) malloc(strlen(param)+1);
	for (i=0; param[i] != '\0'; i++){
		switch (param[i]){
			case 's':
				types[i] = DT_SOCK;
				break;
			case 'l':
				types[i] = DT_LNK;
				break;
			case 'r':
				types[i] = DT_REG;
				break;
			case 'b':
				types[i] = DT_BLK;
				break;
			case 'd':
				types[i] = DT_DIR;
				break;
			case 'c':
				types[i] = DT_CHR;
				break;

			default:
				fprintf(stderr, "Requested type %c not supported\n", param[i]);
				break;
		}
	}

	types[i]='\0';

	return types;
}

// TODO Fix resolvepwd to accept numeric uids as argument
uid_t resolvepwd(char *param){
		struct passwd *pwd;

		if (isdigit(param[0]))
			return (uid_t) atoi(param);

		pwd = getpwnam(param);
		if (pwd == NULL){
			fprintf(stderr, "No such username %s\n", param);
			exit(EXIT_FAILURE);
		}
		return pwd->pw_uid;
}

// TODO Fix resolvegrp to accept numeric gids as argument
gid_t resolvegrp(char *param){
		struct group *grp;
		
		if (isdigit(param[0]))
			return (gid_t) atoi(param);

		grp = getgrnam(param);
		if (grp == NULL){
			fprintf(stderr, "No such group %s\n", param);
			exit(EXIT_FAILURE);
		}
		return grp->gr_gid;
}
