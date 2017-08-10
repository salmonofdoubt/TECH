/* SRE-U CO2 C Programming - Project Exam
 * Author: Rodrigo Ribeiro
 *
 * main.c
 */


#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include "env.h"
#include "find.h"

void usageshort(char *pname, FILE *out){
	printf(
"Usage:\n"
"%s [-h] [-d <depth] [dir]\n"
"\t\tIf [dir] is not provided, the program defaults to the current working dir\n\n"
			, pname);

	return;
}

void usage(char *pname, FILE *out){
	usageshort(pname, out);
	printf(
"\t-h\t\tprints this help message\n"
//"\t-n\t\tmatches only files matching exact name provided\n"
//"\t-t\t\tmatches only provided types\n"
//"\t\t\t\tSupported types are:\n"
//"\t\t\t\t\tr regular files\n"
//"\t\t\t\t\td directories\n"
//"\t\t\t\t\tl symbolic links\n"
//"\t\t\t\t\ts sockets\n"
//"\t\t\t\t\tb block devices\n"
//"\t\t\t\t\tc character devices\n"
//"\t-o\t\tonly entries owned by given user\n"
//"\t-g\t\tonly entries owned by given group\n"
//"\t-s\t\tonly entries larger than given size\n"
"\t-d\t\tlimit directory traversal depth\n");
	
	return;
}

int main(int argc, char **argv){
	findopts_t *fopts;
	int opt;
	char *basedir;

	fopts = (findopts_t *) malloc(sizeof(findopts_t));
	fopts->flags = 0;

	while ((opt = getopt(argc, argv, "hn:t:o:g:s:d:")) != -1){
		switch (opt){
			case 'h':
				usage(argv[0], stdout);
				exit(EXIT_SUCCESS);

			case 'n':
				fopts->flags = fopts->flags | BY_NAME;
				fopts->name = optarg;
				break;

			case 't':
				fopts->flags = fopts->flags | BY_TYPE;
				fopts->mode = resolvetype(optarg);
				break;

			case 'o':
				fopts->flags = fopts->flags | BY_UID;
				fopts->uid = resolvepwd(optarg);
				break;

			case 'g':
				fopts->flags = fopts->flags | BY_GID;
				fopts->gid = resolvegrp(optarg);
				break;

			case 's':
				fopts->flags = fopts->flags | BY_SIZE;
				fopts->min_size = atoi(optarg);
				break;

			case 'd':
				fopts->flags = fopts->flags | MAX_DEPTH;
				fopts->max_depth = atoi(optarg);
				break;

			default:
				usage(argv[0], stderr);
				exit(EXIT_FAILURE);
		}
	}

	if (optind < argc)
		basedir = argv[optind];
	else
		basedir = ".";

	find(basedir, fopts);

	exit(EXIT_SUCCESS);	
}
