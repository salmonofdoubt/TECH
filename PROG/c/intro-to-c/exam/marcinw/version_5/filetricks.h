#ifndef FILE_TRICKS
#define FILE_TRICKS 1

void fail_miserably(const char* message);

extern char* get_full_path(const char* path, const char* filename);

extern char get_filetype(struct stat* buff);

extern char print_dir( const char* path, 
                       char        has_name_filter, 
                       const char* name_filter,
                       char        has_type_filter, 
                       const char* type_filter,
                       uid_t       uid,
                       gid_t       gid,
                       long        min_size,
                       int         max_recursion );

#endif