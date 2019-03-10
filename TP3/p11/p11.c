#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define BUFF_SIZE 256
#define MAX_ARGS 15

int main(int argc, char * argv[],char * envp[]) {
    
char buffer[BUFF_SIZE];
char * args[MAX_ARGS];

while(1) {
    write(STDOUT_FILENO,"\nminish> ",8);
    fgets(buffer,sizeof(buffer),stdin);

    if(strcmp(buffer,"quit\n") == 0) {
        break;
    }

    char* token;
    token = strtok(buffer," ");
    args[0] = token;
    int i = 1;
    for(;i<MAX_ARGS;i++) {
        token = strtok(NULL, " ");
        if(token == NULL) {
            args[i] = NULL;
            break;
        }

        args[i] = token;
    }

    args[i-1][strlen(args[i-1])-1] = '\0'; //replace \n character with \0
    
    

    if(fork() > 0) {
        int stat;
        wait(&stat);
    }
    else {
    
    if(i>= 3 && strcmp(args[i-2],"-o") == 0) {
        int fd = open(args[i-1],O_WRONLY|O_CREAT|O_TRUNC,00644);
        if(fd == -1) {
            write(STDOUT_FILENO,"\nFailed to open file. Writing in stdout.\n",41);
            break;
        }
        dup2(fd,STDOUT_FILENO);

        args[i-2] = NULL;
    }
        
        execvp(args[0],args);
        write(STDOUT_FILENO,"Failed to execute!\n",19);
        exit(1);
    }

}
    
    exit(0);
}