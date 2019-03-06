#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void get_permissions(char *permissions, mode_t mode){

  /*Determine the file type*/
  if (S_ISREG(mode)){
    permissions[0] = '-';
  }else if(S_ISDIR(mode)){
    permissions[0] = 'd';
  }else if(S_ISCHR(mode)){
    permissions[0] = 'c';
  }else if(S_ISBLK(mode)){
    permissions[0] = 'b';
  }else if(S_ISSOCK(mode)){
    permissions[0] = 's';
  }else if(S_ISLNK(mode)){
    permissions[0] = 'l';
  }else {
    permissions[0] = '-';
  }

  /*Determine file open modes*/
  /*Owner*/
  if(S_IRUSR & mode){
    permissions[1] = 'r';
  } else {
    permissions[1] = '-';
  }
  if(S_IWUSR & mode){
    permissions[2] = 'w';
  } else {
    permissions[2] = '-';
  }
  if(S_IXUSR & mode){
    permissions[3] = 'x';
  } else {
    permissions[3] = '-';
  }
  if(S_ISUID & mode){
    if(S_IXUSR & mode)
      permissions[3] = 'S';
    else
      permissions[3] = 's';
  }
  
  /*Group*/
  if(S_IRGRP & mode){
    permissions[4] = 'r';
  } else {
    permissions[4] = '-';
  }
  if(S_IWGRP & mode){
    permissions[5] = 'w';
  } else {
    permissions[5] = '-';
  }
  if(S_IXGRP & mode){
    permissions[6] = 'x';
  } else {
    permissions[6] = '-';
  }
  if(S_ISGID & mode){
    if(S_IXGRP & mode)
      permissions[6] = 's';
    else
      permissions[6] = 'S';
  }

  /*Others*/
  if(S_IROTH & mode){
    permissions[7] = 'r';
  } else {
    permissions[7] = '-';
  }
  if(S_IWOTH & mode){
    permissions[8] = 'w';
  }else {
    permissions[8] = '-';
  }
  if(S_IXOTH & mode){
    permissions[9] = 'x';
  } else {
    permissions[9] = '-';
  }
  //  permissions[10] = '\0';
}

void get_ls_time(const char * mod_time, char * ls_time){
  int start = 4;
  for(; start <= 15; start++){
    ls_time[start - 4] = mod_time[start];
  }
  ls_time[start - 4] = '\0';
}

void print_the_stat(const struct stat * stats, const char * filename){

  char permissions[11] = {'\0'};
  char mod_time[12] = {'\0'};
  //  bzero(permissions, 10);
  
  get_permissions(permissions, stats->st_mode);
  struct passwd * user = getpwuid(stats->st_uid);
  struct group * group = getgrgid(stats->st_gid);

  get_ls_time(asctime(localtime(&(stats->st_mtime))), mod_time);

  printf("%-10s %-2u %-9s %-7s %8lld %-12s %-20s\n", permissions, 
	 (unsigned int) stats->st_nlink, user->pw_name, 
	 group->gr_name, (long long)stats->st_size, mod_time, filename);

}

struct dirent* get_contents_of_dir(DIR * directory){
  return readdir(directory);
}

DIR * open_the_dir(const char * dirname){
  return opendir(dirname);
}

int comp_str(const void *a, const void *b){
  const char **ia = (const char **)a;
  const char **ib = (const char **)b;
  return strcmp(*ia, *ib);
}

char * get_fullpath(const char * dir_n, const char * file_n){
  char * full_path;
  int d_len = strlen(dir_n);
  int f_len = strlen(file_n);

  full_path = (char *) malloc(d_len + f_len);
  strcpy(full_path, dir_n);
  strcat(full_path, file_n);

  return full_path;
}

void print_directory_contents( DIR * dir_p, const char * dir_n ){
  struct dirent * content = NULL;

  char ** filenames = (char **) malloc(sizeof(char **));
  char * filename = NULL;
  int count = 1;
  while((content = get_contents_of_dir(dir_p))!= NULL){
    /* skip hidden files */
    if (content->d_name[0] == '.') 
      continue;

    filenames = (char **) realloc(filenames, count * sizeof(char **));

    filename = (char *) malloc(strlen(content->d_name) + 1);
    bzero(filename, strlen(content->d_name) + 1);
    strcpy(filename, content->d_name);
    filenames[count - 1] = filename;

    filename = NULL;
    count++;

  }
  count--;
  /*Handle error from readdir*/
  if(errno < 0){
    perror("Error occured in readdir().. exitting...\n");
    exit(3);
  }

  /*order the filenames*/
  qsort(filenames, count, sizeof(*filenames), comp_str);

  int i;
  /*print ordered list of filenames*/
  for(i = 0; i < count; i++){
    printf("%s\n",filenames[i]);
  }

  /*print ordered stats on filenames*/
  char * fname = NULL;
  for(i = 0; i < count; i++){
    struct stat statistics;
    fname = get_fullpath(dir_n, filenames[i]);

    lstat(fname, &statistics);
    print_the_stat(&statistics, filenames[i]);

    free(fname);
    fname = NULL;
  }

  /*  free up the memory held by filenames*/
  for(i = 0; i < count; i++){
    free(filenames[i]);
  }
  free(filenames);
  
}

char* normalise_dir_name(const char * dirname){
  char * normalised;
  int dir_name_len = strlen(dirname);

  //strcat(normalised_dir_name, argv[1]);
  if(dirname[dir_name_len - 1] != '/'){
    /* check whether filename is a proper dirname and 
       append an allowance to creat a full path name */
    dir_name_len += 1;
    normalised = (char *) malloc(dir_name_len);
    strcpy(normalised, dirname);
    strcat(normalised, "/");
  } else {
    normalised = (char *) malloc(dir_name_len);
    strcpy(normalised, dirname);
  }

  return normalised;
}

int main(int argc, char *argv[]){
  
  if (argc != 2){
    printf("please give a second argument... exitting...\n");
    exit(1);
  }

  char * dir_name = normalise_dir_name(argv[1]);

  DIR * dir_p = open_the_dir(dir_name);
  if (dir_p == NULL){
    perror("Error experienced! exitting...\n");
    exit(2);
  }

  /*Print the directory contents*/
  print_directory_contents(dir_p, dir_name);

  free(dir_name);
}
