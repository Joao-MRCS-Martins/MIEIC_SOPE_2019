#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFF_SIZE 512

int main(int argc, char * argv[], char * envp[]) {

    if(argc != 3) {
        printf("Usage: %s <src_dir> <dest_dir>\n",argv[0]);
        exit(1);
    }

    DIR *dirp;
    struct dirent *direntp;
    struct stat stat_buf;
    char *str;
    char buffer[BUFF_SIZE];
    char * fullpath = malloc(BUFF_SIZE);
    
    if((dirp = opendir(argv[1])) == NULL) {
        perror(argv[1]);
        exit(1);
    }
    
    getcwd(buffer,BUFF_SIZE);
    if(strcmp(argv[2],"."))
        strcat(buffer,argv[2]);
    chdir(argv[1]);
    
    while ((direntp = readdir(dirp))!=NULL) {
        if(stat(direntp->d_name,&stat_buf) ==0) {
            if(fork() ==0) {
                if(S_ISREG(stat_buf.st_mode)) {
                    execlp("cp","cp",direntp->d_name,buffer,NULL);
                }
                else if(S_ISDIR(stat_buf.st_mode)) {
                    if(strcmp(direntp->d_name,".") != 0 || strcmp(direntp->d_name,"..") !=0) {
                        execlp("mkdir","mkdir",direntp->d_name,buffer,NULL);
                    }
                }
                exit(0);
            }
        }
    }
    closedir(dirp);
    exit(0);
}