#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 512
int main(int argc, char *argv[])
{
 DIR *dirp;
 struct dirent *direntp;
 struct stat stat_buf;
 char * str;
 char buff[BUFFER_SIZE];
 if (argc != 2)
 {
  fprintf( stderr, "Usage: %s dir_name\n", argv[0]);
  exit(1);
 }

 if ((dirp = opendir( argv[1])) == NULL)
 {
  perror(argv[1]);
  exit(2);
 }

 printf("%s\n",getcwd(buff,BUFFER_SIZE));
 chdir(argv[1]);
 
 while ((direntp = readdir( dirp)) != NULL)
 {
  if (lstat(direntp->d_name, &stat_buf)==-1)   // testar com stat()
  {
   perror("lstat ERROR");
   closedir(dirp);
   exit(3);
  }
  printf("%-10d - ", (int) stat_buf.st_ino);
  if (S_ISREG(stat_buf.st_mode))
    str = "regular";
  else if (S_ISDIR(stat_buf.st_mode)) 
    str = "directory";
  else 
    str = "other";
  printf("%-25s - %s\n", direntp->d_name, str);
 }

 closedir(dirp);
 exit(0);
}

