#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void *PrintHello(void *threadnum) {
    sleep(1);
    printf("Tid: %ld\n", pthread_self());
    return threadnum;
}

int main(int argc, char* argv[]) {

    if(argc != 2) {
        printf("Usage: %s <num_thread>\n",argv[0]);
        exit(1);
    }
    int num = atoi(argv[1]);
    pthread_t threads[num];
    int t[num];
    void* ret = malloc(sizeof(int));
    for(int i =0; i< num; i++) {
        t[i] =i;
        printf("Creating thread %d\n", t[i]);
        pthread_create(&threads[i], NULL, PrintHello, (void *)&t[i]);
    }
    for(int i =0; i<num; i++) {
        pthread_join(threads[i],&ret);
        printf("Thread nº %d\n",*(int *) ret);
    }
    pthread_exit(0);
}