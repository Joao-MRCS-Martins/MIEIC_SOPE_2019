#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 

int main(void) {
    printf("1\n");
    if(fork() > 0) {
        printf("2\n");
        printf("3\n");
    } else {
        printf("4\n");
        printf("5\n");
    }
    printf("\n");
    return 0;
}