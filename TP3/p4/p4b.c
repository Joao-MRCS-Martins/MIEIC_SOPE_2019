#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int stat;
    if(fork() > 0) {
        printf("Hello ");
    } else {
        printf("World!\n");
    }
    
    return 0;
}