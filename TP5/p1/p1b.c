#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

struct numbers{
    int x;
    int y;
} ;

int main(void) {
    int fd[2];
    pid_t pid;
    pipe(fd);
    pid = fork();
    if (pid >0) {
        struct numbers n;
        printf("PARENT:\n");
        printf("x y ? "); 
        scanf("%d %d",&n.x,&n.y);
        close(fd[READ]);
        write(fd[WRITE],&n,sizeof(struct numbers));
        close(fd[WRITE]);
    }
    else {
        struct numbers n;
        close(fd[WRITE]);
        read(fd[READ],&n,sizeof(struct numbers));
        printf("SON:\n");
        printf("x + y = %d\n", n.x+n.y);
        printf("x - y = %d\n",n.x-n.y);
        printf("x * y = %d\n",n.x*n.y);
        if(n.y ==0)
            printf("x / y = 0\n");
        else
            printf("x / y = %d\n",n.x/n.y);
        
        close(fd[READ]);
    }
    return 0;
}