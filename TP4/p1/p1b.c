#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void sigint_handler(int signo) {
    printf("In SIGINT handler ...\n");
    
}

int main(void) {
    if (signal(SIGINT,sigint_handler) < 0) {
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);
    }

    if(signal(SIGUSR1,SIG_IGN) == SIG_ERR) {
        fprintf(stderr,"Unable to ignore the signal.\n");
        exit(2);
    }
    
    printf("Sleeping for 30 seconds ...\n");
    
    int secs = sleep(30);
    while(secs != 0)
        secs = sleep(secs);
    
    printf("Waking up ...\n");
    exit(0);
}