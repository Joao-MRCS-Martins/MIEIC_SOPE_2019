#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define STDERR 2

int n = 50000;
void * thrfunc(void * arg) {
    void* ret;

    int num =0;
    while(n > 0) {
        write(STDERR,arg,1);
        n--;
        num++;
    }
    ret = malloc(sizeof(int));
    *(int*) ret = num;
    return ret;
}

int main() {
    pthread_t ta, tb;
    char a = 'a';
    char b = 'b';
    pthread_create(&ta, NULL, thrfunc, &a);
    pthread_create(&tb, NULL, thrfunc, &b);
    void* n1; void* n2;
    pthread_join(ta, &n1);
    pthread_join(tb, &n2);
    printf("\nNumber of 'a' printed: %d\n",*(int*)n1);
    printf("Number of 'b' printed: %d\n",*(int*)n2);
    free(n1);
    free(n2);
    return 0;
}