#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 10000

void * thrfunc(void * arg) {
    int i;
    fprintf(stderr, "Starting thread %d\n", (int *) arg);
    for (i = 1; i <= NUMITER; i++) 
        write(STDERR,arg,1);
    return NULL;
}

void * thrfunc_v2(void * arg) {
    int i;
    fprintf(stderr, "Starting thread %d\n", (char* ) arg);
    for (i = 1; i <= NUMITER; i++) 
        write(STDERR,arg,1);
    return NULL;
}
int main() {
    pthread_t ta, tb;
    int t1 = 1;
    char t2 = 2;
    pthread_create(&ta, NULL, thrfunc, &t1);
    pthread_create(&tb, NULL, thrfunc_v2, &t2);
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    return 0;
}