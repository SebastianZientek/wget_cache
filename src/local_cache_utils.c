#include <openssl/md5.h>
#include <stdbool.h>
#include <stdio.h>

#include "wget.h"
#include "utils.h"
#include "init.h"

bool is_caching_allowed()
{
  if (opt.output_document && strcmp(opt.output_document, "-") == 0)
  {
    return false;
  }
  else if (opt.spider)
  {
    return false;
  }
  else if (!opt.use_local_cache)
  {
    return false;
  }

  return true;
}

char *cache_directory_for_url(char *url)
{
  unsigned char obuf[16];
  unsigned char str_md5[33];
  str_md5[32] = '\0';
  MD5(url, strlen(url), obuf);
  for (int i = 0, j = 0; i < 16; i++, j += 2)
  {
    sprintf(str_md5 + j, "%02x", obuf[i]);
  }

  char *cached_directory = ajoin_dir_file(opt.homedir, ".cached_wget");
  {
    struct stat st = {0};
    if (stat(cached_directory, &st) == -1)
    {
      mkdir(cached_directory, 0700);
    }
  }

  char *cached_md5_dir = ajoin_dir_file(cached_directory, str_md5);
  {
    struct stat st = {0};
    if (stat(cached_md5_dir, &st) == -1)
    {
      mkdir(cached_md5_dir, 0700);
    }
  }

  return cached_md5_dir;
}

int copy_file(char *dest_name, char *src_name)
{
  FILE *f_src, *f_dest;

  f_src = fopen(src_name, "rb");
  f_dest = fopen(dest_name, "wb");

  if (f_src == NULL)
  {
    printf("A Copying file error: %s -> %s\n", src_name, dest_name);
    return -1;
  }

  if (f_dest == NULL)
  {
    printf("B Copying file error: %s -> %s\n", src_name, dest_name);
    fclose(f_src);
    return -1;
  }

  while (1)
  {
    int d = fgetc(f_src);

    if (!feof(f_src))
    {
      fputc(d, f_dest);
    }
    else
    {
      break;
    }
  }

  fclose(f_dest);
  fclose(f_src);
  return 0;
}
