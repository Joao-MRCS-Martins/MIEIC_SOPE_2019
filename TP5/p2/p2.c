#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main(void) {
    int fd[2];
    int fd2[2];
    pid_t pid;
    pipe(fd);
    pipe(fd2);
    pid = fork();
    if (pid >0) {
        int a[2];
        printf("PARENT:\n");
        printf("x y ? "); 
        scanf("%d %d",&a[0],&a[1]);
        close(fd[READ]);
        write(fd[WRITE],a,2*sizeof(int));
        close(fd[WRITE]);

        int res[4];
        close(fd2[WRITE]);
        read(fd2[READ],res,4*sizeof(int));
        printf("PARENT reading results\n");
        printf("x + y = %d\n", res[0]);
        printf("x - y = %d\n",res[1]);
        printf("x * y = %d\n",res[2]);
        if(res[1] ==0)
            printf("x / y = 0\n");
        else
            printf("x / y = %d\n",res[3]);
    }
    else {
        int b[2];
        close(fd[WRITE]);
        read(fd[READ],b,2*sizeof(int));
        printf("SON:\nCalculating...\n");
        int res[4] = {b[0]+b[1],b[0]-b[1],b[0]*b[1],0};
        if(b[1] != 0)
            res[3] = b[0]/b[1];
        printf("Sending results to PARENT...\n");
        close(fd2[READ]);
        write(fd2[WRITE],res,4*sizeof(int));
        close(fd2[WRITE]);
    }
    return 0;
}