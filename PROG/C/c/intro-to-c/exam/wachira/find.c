/*#define _GNU_SOURCE*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "findlib.h"

void Usage(char ** const args){
    fprintf(stderr, "SYNOPSIS\n \t%s [dirname] [-n name] [-t type] [-o uid]\
 [-g gid] [-s size] [-d depth]\n", args[0]+2);
}

static const char * optstring = "n:t:o:g:s:d:";
void parse_opts(char ** const args, const int argc, findopts * const opts){
  int opt; /**/
  while((opt = getopt(argc, args, optstring )) != -1){
    switch(opt){
    case 'n': (*opts).name = optarg; break;
    case 't': (*opts).type = optarg; break;
    case 'o': (*opts).uid = atoi(optarg); break;
    case 'g': (*opts).gid = atoi(optarg); break;
    case 's': (*opts).size = atoi(optarg); break;
    case 'd': (*opts).depth = atoi(optarg); break;
    default: Usage(args); exit(EXIT_FAILURE); /*print synopsis and terminate*/
    } /* end swith block*/
  } /*end while block*/
  if (optind <= (argc - 1)) (*opts).dirname = args[optind]; /*take the first directory name :)*/
}

void normalise_parent_dir(const char * parent_dir, char ** const target_name){
  int dir_len = strlen(parent_dir);
  if(parent_dir[dir_len - 1] != '/'){
    strcpy(*target_name, parent_dir);
    strcat(*target_name, "/");
  } else
    strcpy(*target_name, parent_dir);
}

void get_fullpath(const char * dir_path, const char * file_name,
		  char ** const target_path ){
  strcpy(*target_path, dir_path);
  /*normalise*/
  normalise_parent_dir(dir_path, target_path);
  strcat(*target_path, file_name);
}

void match_the_files(const char * absolute_path, const char * filename,
		     const findopts * const opts,
		     const int match_pred, match_func name_match, 
		     match_func size_match, match_func uid_match, 
		     match_func gid_match, match_func type_match){
  struct stat filestats;
  int status = lstat(absolute_path, &filestats);
  if(status != 0){
    perror("\n\t EXCEPTION: cannot lstat()\n");
    return;
  }

  entry e;

  strcpy(e.name, filename);
    /*Determine the file type*/
  if ( S_ISREG(filestats.st_mode) ){
    strcpy(e.type,"r\0");
  }else if(S_ISDIR(filestats.st_mode)){
    strcpy(e.type,"d\0");

    DIR * parent = opendir(absolute_path);
    struct dirent * contents;
    while((contents = readdir(parent)) != NULL ){
      if(contents->d_name[0] == '.') continue;
      char * full_path = (char *) malloc(strlen(absolute_path) + \
					 strlen(contents->d_name) + 2);
      get_fullpath(absolute_path, contents->d_name, &full_path);

    /*match the files - recurssion*/
      match_the_files(full_path, contents->d_name, opts, match_pred, 
		    name_match, size_match, uid_match, gid_match, type_match);
      free(full_path);
    }
  }else if(S_ISCHR(filestats.st_mode)){
    strcpy(e.type,"c\0");
  }else if(S_ISBLK(filestats.st_mode)){
    strcpy(e.type,"b");
  }else if(S_ISSOCK(filestats.st_mode)){
    strcpy(e.type,"s\0");
  }else if(S_ISLNK(filestats.st_mode)){
    strcpy(e.type,"l\0");
  }
  e.uid = filestats.st_uid;
  e.gid = filestats.st_gid;
  e.size = filestats.st_size;
  
  /*call the match functions*/
  int print_mask = 31; /*0x0000001F check for integrity*/
  print_mask &= name_match((const void *)&e, (const void *) opts);
  print_mask &= size_match((const void *)&e, (const void *) opts);
  print_mask &= uid_match((const void *)&e, (const void *) opts);
  print_mask &= gid_match((const void *)&e, (const void *) opts);
  print_mask &= type_match((const void *)&e, (const void *) opts);
  
  /*  if(print_mask == match_pred)*/
    fprintf(stderr, "%s\n", absolute_path);

}

int get_print_predicate(const findopts * opts){
  int print_pred = 0;
  if (opts->uid != -1) print_pred |= 4;
  if (opts->gid == -1) print_pred |= 8; 
  if (opts->size != -1) print_pred |= 1;
  if (opts->name != NULL) print_pred |= 2;
  if (opts->type != NULL) print_pred |= 16;
  return print_pred;
}

void find_files(const findopts * opts){
  DIR * parent = opendir(opts->dirname);
  int match_pred = get_print_predicate(opts);
  if(parent != NULL){
    struct dirent * contents;
    while((contents = readdir(parent)) != NULL ){
      if(contents->d_name[0] == '.') continue;
        char * full_path = (char *) malloc(strlen(opts->dirname) + \
					   strlen(contents->d_name) + 2);
	get_fullpath(opts->dirname, contents->d_name, &full_path);

	match_the_files(full_path, contents->d_name, opts, match_pred, 
		    name_match, size_match, uid_match, gid_match, type_match);
      free(full_path);
    }
  }else { 
    perror("Error opening dir: opendir()"); exit(EXIT_FAILURE);
  }
}

void normalise_opt_parent_dir(findopts * opt){
  char * normalised = (char *) malloc(strlen((*opt).dirname) + 1);
  normalise_parent_dir((*opt).dirname, &normalised );
  (*opt).dirname = normalised;
  normalised = NULL;
}

int main(int argc, char *argv[]){
  findopts opts; /*and initialise to default values*/
  opts.dirname = "."; opts.uid = -1; opts.gid = -1; opts.size = -1;
  opts.depth = 0; opts.name = NULL; opts.type = NULL;

  parse_opts(argv, argc, &opts); /*get all the opts passed to the program*/
  normalise_opt_parent_dir(&opts);
  find_files(&opts);

  exit(EXIT_SUCCESS);
}
