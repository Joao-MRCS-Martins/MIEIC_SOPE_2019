#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int add = 1;

void sigusr_handler(int signo) {
    printf("In SIGUSR handler ...\n");
    if(signo == SIGUSR1)
        add = 1;
    else
        add = 0;
    printf("Exiting SIGUSR1 handler.\n");
}

int main() {
    int v =0;

    if (signal(SIGUSR1,sigusr_handler) < 0) {
        fprintf(stderr,"Unable to install SIGUSR1 handler\n");
        exit(1);
    }

    if (signal(SIGUSR2,sigusr_handler) < 0) {
        fprintf(stderr,"Unable to install SIGUSR2 handler\n");
        exit(1);
    }

    while(1) {
        if(add==1)
            v++;
        else
            v--;
        printf("v: %d\n",v);
        sleep(1);
    }

    exit(0);
}