#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/types.h>

#define LOOP_NUM 50

int v =0;
void sigusr_handler(int signo) {
   if(signo == SIGUSR1)
        v++;
    else
        v--;
    printf("v = %d\n",v);
}

int main() {
    
    int frk;
    srand(time(NULL));
    
    if (signal(SIGUSR1,sigusr_handler) < 0) {
        fprintf(stderr,"Unable to install SIGUSR1 handler\n");
        exit(1);
    }

    if (signal(SIGUSR2,sigusr_handler) < 0) {
        fprintf(stderr,"Unable to install SIGUSR2 handler\n");
        exit(1);
    }
    
    if((frk =fork()) != 0) {
       for(int i =0; i < LOOP_NUM; i++) {
            int sign = rand() % 2;
            
            if (sign ==0) {
                kill(frk,SIGUSR1);
            }
            else {
                kill(frk,SIGUSR2);
            }
            sleep(1);
        }
    }
    else {
        while(1) pause();
    }
    
    printf("Im a wizard\n");
    exit(0);
}