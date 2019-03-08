#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int stat;
    if(fork() > 0) {
        wait(&stat);
        printf("World!\n");
    } else {
        printf("Hello ");
    }
    
    return 0;
}