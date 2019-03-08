#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int stat;
    if(fork() > 0) {
        if(fork() >0) {
            printf("my ");
        }
        else {
            printf("friends!\n");
        }
    } else {
        printf("Hello ");
    }
    
    return 0;
}