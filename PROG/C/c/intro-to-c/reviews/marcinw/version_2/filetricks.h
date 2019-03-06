#ifndef FILE_TRICKS
#define FILE_TRICKS 1

extern char* get_full_path(const char* path, const char* filename);

extern char* get_filetype(struct stat* buff);

extern void print_dir(const char* path, char has_filter, const char* filter);

#endif