#ifndef LOCAL_CACHE_UTILS_H
#define LOCAL_CACHE_UTILS_H

bool is_caching_allowed();
int copy_file(char  *dest_name, char *src_name);
char *cache_directory_for_url(char *url);

#endif
