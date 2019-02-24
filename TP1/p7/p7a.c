#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //alinea b

void exit_1(){
    printf("Executing handler 1\n");
    
}

void exit_2(){
    printf("Executing handler 2\n");
    _exit(0); //alinea b
}

int main(){
    
    atexit(exit_1); 
    atexit(exit_2); 
    printf("Main done!\n");
    return 0;
}