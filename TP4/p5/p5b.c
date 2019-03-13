#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void sigchld_handler(int signo) {
    printf("Entering SIGCHLD handler ...\n");
    wait(NULL);
    printf("Exiting SIGCHLD handler ...\n");
}

int main(void) {
    
    struct sigaction action;
    action.sa_handler = sigchld_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    
    pid_t pid;
    int i,n;
    if (sigaction(SIGCHLD,&action,NULL) < 0) {
        fprintf(stderr,"Unable to install SIGCHLD handler\n");
        exit(1);
    }

    for(i = 1; i <=10 ; i++) {
        
        if((pid = fork()) == 0) {
            int secs;
            printf("CHILD no. %d (PID=%d) working ... \n",i,getpid());
            while((secs = sleep(15) !=0)) {
                secs = sleep(secs);
            }
            printf("CHILD no. %d (PID=%d) exiting ... \n",i,getpid());
            exit(0);
        }
    }

     for (int i=1 ;i<=4; i++ ) {
        printf("PARENT: working hard (task no. %d) ...\n",i);
        n=20; while((n=sleep(n))!=0);
        printf("PARENT: end of task no. %d\n",i);
        printf("PARENT: waiting for child no. %d ...\n",i);
    }
    
    exit(0);
}