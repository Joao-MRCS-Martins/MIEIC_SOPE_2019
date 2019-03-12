#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo) {
    printf("In SIGINT handler ...\n");
}

int main(void) {

    struct sigaction action;
    action.sa_handler = sigint_handler;

    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    
    sigaction(SIGINT,&action,NULL);
    printf("Sleeping for 30 seconds ...\n");

    int secs = sleep(30);
    while(secs != 0) {
        secs = sleep(secs);
    }

    printf("Waking up ...\n");
    exit(0);
}