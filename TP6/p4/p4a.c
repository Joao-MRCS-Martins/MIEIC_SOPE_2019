#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void *PrintHello(void *threadnum) {
    sleep(1);
    printf("Thread nº %d tid: %ld\n",*((int*) threadnum),  pthread_self());
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {

    if(argc != 2) {
        printf("Usage: %s <num_thread>\n",argv[0]);
        exit(1);
    }
    int num = atoi(argv[1]);
    pthread_t threads[num];
    int t[num];
    for(int i =0; i< num; i++) {
        t[i] =i;
        printf("Creating thread %d\n", t[i]);
        pthread_create(&threads[i], NULL, PrintHello, (void *)&t[i]);
    }
    pthread_exit(0);
}