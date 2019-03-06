#include "find.h"

void PrintEntry(struct dirent *dirent, char *filename, const char *name,
                const int type, const int uid, const int gid, const int size){
  struct stat buf;
  lstat(filename, &buf);

  if (!(name == NULL || !strcmp(dirent->d_name, name))){
    return;
  }
  if (uid && uid != buf.st_uid) return;
  if (gid && gid != buf.st_gid) return;
  if ((type != 0) && (type == dirent->d_type)){
    return;
  }

  printf("%s\n", filename);
}

void ReadDir(DIR *dp, char *dir, const char depth_set, char depthc,
             const char depth, const char *name, const int type,
             const int uid, const int gid, const int size){
  DIR *child_dp;
  struct dirent *dirent;
  int realloc_size; 
  char *filename;
  ssize_t buffsize;

  while ((dirent=readdir(dp))) {
    filename = malloc(BUFFSIZE);
    bzero(filename, BUFFSIZE);
    buffsize = BUFFSIZE;
    if ((depth_set && !(depthc < depth))){
      return;
    }
    while ((realloc_size = snprintf(filename, buffsize, "%s/%s", dir,
                                    dirent->d_name)) > buffsize){
      buffsize = realloc_size + buffsize;
      filename = realloc(filename, buffsize);
    }
      if (strcmp(dirent->d_name, ".") && strcmp(dirent->d_name, "..")){
        PrintEntry(dirent, filename, name, type, uid, gid, size);
        if (dirent->d_type & DT_DIR){
          if ((child_dp = opendir(filename)) != NULL){
            ReadDir(child_dp, filename, depth_set, depthc+1, depth, name, type,
                    uid, gid, size);
          }
        }
      }
    free(filename);
  }
}

void Find(int dir_count, char **dirs, const char depth_set, char depthc,
          const char depth, const char *name, const int type, const int uid,
          const int gid, const int size){
  int i;
  DIR *dp;
  for (i=0; i<dir_count; i++){
    if ((dp = opendir(dirs[i]))){
      printf("%s\n", dirs[i]);
//      printf("1");
      ReadDir(dp, dirs[i], depth_set, depthc, depth, name, type, uid, gid,
              size);
    }
    else {
      printf("find: \'%s\': No such file or directory", dirs[i]);
    }
  }
}
