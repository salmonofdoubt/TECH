// leczb: Good call *not* defining _GNU_SOURCE (as it is not GNU code)
/*#define _GNU_SOURCE*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "findlib.h"

// leczb: Style: function names should be all lower-case.
//        Minor: the const qualifier should apply to char * not args. Also,
//               it's common practice to just pass in arg[0] to the usage()
//               function:
//          void usage(const char *progname) {
void Usage(char ** const args){
  // leczb: the args[0]+2 is not correct. It should be args[0]. What if args[0] is
  //        one char long?
  //        Style: it's best practice to use implicit string concatenation for
  //               multi-line strings:
  //
  //               fprintf(stderr, "first line\n"
  //                               "second line\n", ...:w
  //                               );
  //               
    fprintf(stderr, "SYNOPSIS\n \t%s [dirname] [-n name] [-t type] [-o uid]\
 [-g gid] [-s size] [-d depth]\n", args[0]+2);
}

// leczb: no need to make it static. It's a global variable already.
static const char * optstring = "n:t:o:g:s:d:";
// leczb: Minor style comment: the common order of these args is: argc, args.
void parse_opts(char ** const args, const int argc, findopts * const opts){
  int opt; /**/
  // leczb: Style: space is required between while/switch and "("
  while((opt = getopt(argc, args, optstring )) != -1){
    switch(opt){
      // leczb: Style: (*opts).name is equivalent to opts->name. The latter is
      //        the preferred and idiomatic form.
    case 'n': (*opts).name = optarg; break;
    case 't': (*opts).type = optarg; break;
              // leczb: FYI: atoi() is not able to convert every possible UID as
              //        UIDs are 32 bit unsigned integers on most platforms.
              //        Applies to uid, gid and size as well.
    case 'o': (*opts).uid = atoi(optarg); break;
    case 'g': (*opts).gid = atoi(optarg); break;
    case 's': (*opts).size = atoi(optarg); break;
    case 'd': (*opts).depth = atoi(optarg); break;
    default: Usage(args); exit(EXIT_FAILURE); /*print synopsis and terminate*/
    } /* end swith block*/
  } /*end while block*/
  // leczb: Minor: (optind <= (argc - 1)) is equivalent to (optind < argc),
  //        which looks simpler and more readable.
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
    // leczb: What's the extra zero byte doing there? A string literal is
    //        terminated by zero for you by the compiler automatically.
    strcpy(e.type,"r\0");
  }else if(S_ISDIR(filestats.st_mode)){
    // leczb: Portability: you are mixing instructions and variable
    //        declarations. gcc says:
    //        "ISO C90 forbids mixed declarations and code"
    strcpy(e.type,"d\0");

    // leczb: You are opening the dir, but you are not closing it.
    //        This is a filedescriptor leak. Try to set your
    //        filedescriptor limit to something ridiculosly low
    //        and try to run your program against a deep directory
    //        structure to see what happens:
    //          bash # start a new shell, so ulimit only applies to that
    //          mkdir -p /tmp/1/2/3/4/5/6/7/8/9/10/11
    //          ulimit -n 10
    //          ./find /tmp/1
    DIR * parent = opendir(absolute_path);
    struct dirent * contents;
    while((contents = readdir(parent)) != NULL ){
      // leczb: This is not correct. It's going to skip every filename that
      //        begins with a dot.  Only "." and ".." should be skipped.
      //        ".bashrc" shouldn't be skipped.
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
  
  // leczb: Why is this commented? It means you are not using the result from
  //        the matchers at all.
  /*  if(print_mask == match_pred)*/
  // leczb: Why stderr? Results should be printed to stdout.
    fprintf(stderr, "%s\n", absolute_path);

}

int get_print_predicate(const findopts * opts){
  int print_pred = 0;
  // leczb: Not sure why you store it as a flag field. I would assume a simple
  //        true/false result would be enough.
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
      // leczb: This is incorrect. This is going to skip all filenames beginning
      //        with ".". Only "." and ".." should be skipped.
      if(contents->d_name[0] == '.') continue;
        char * full_path = (char *) malloc(strlen(opts->dirname) + \
					   strlen(contents->d_name) + 2);
	get_fullpath(opts->dirname, contents->d_name, &full_path);

        // leczb: Design comment: you could have passed the pointers to the
        //        matcher functions through an array of function pointers.
        //        It's still correct, just noting.
	match_the_files(full_path, contents->d_name, opts, match_pred, 
		    name_match, size_match, uid_match, gid_match, type_match);
      free(full_path);
    }
  }else { 
    // leczb: I think exiting here is not the right thing to do. You'll might
    //        encounter a number of dirs that you can't open, but you should
    //        continue after printing the error message. At least that's what
    //        the original find utility does.
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
