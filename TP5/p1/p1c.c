#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define READ 0
#define WRITE 1
#define MAX_BUFFER 50

int main(void) {
    int fd[2];
    pid_t pid;
    pipe(fd);
    pid = fork();
    if (pid >0) {
        char a[2][50];
        printf("PARENT:\n");
        printf("x y ? "); 
        scanf("%s %s",&a[0],&a[1]);
        printf("%s\n",a[0]);
        close(fd[READ]);
        write(fd[WRITE],a,MAX_BUFFER*2);
        close(fd[WRITE]);
    }
    else {
        char b[2][50];
        close(fd[WRITE]);
        read(fd[READ],b,2*MAX_BUFFER);
        printf("SON:\n");
        
        printf("x + y = %d\n", atoi(b[0])+atoi(b[1]));
        printf("x - y = %d\n",atoi(b[0])-atoi(b[1]));
        printf("x * y = %d\n",atoi(b[0])*atoi(b[1]));
        if(strcmp(b[1],"0") == 0)
            printf("x / y = 0\n");
        else
            printf("x / y = %d\n",atoi(b[0])/atoi(b[1]));
        
        close(fd[READ]);
    }
    return 0;
}