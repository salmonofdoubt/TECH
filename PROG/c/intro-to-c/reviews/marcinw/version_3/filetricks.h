#ifndef FILE_TRICKS
#define FILE_TRICKS 1

extern char* get_full_path(const char* path, const char* filename);

extern char get_filetype(struct stat* buff);

extern void print_dir( const char* path, 
                       char has_name_filter, 
                       const char* name_filter,
                       char has_type_filter, 
                       const char* type_filter );

#endif