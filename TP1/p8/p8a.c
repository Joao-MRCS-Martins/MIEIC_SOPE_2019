#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Usage: <executable> <n1> <n2>\n");
        exit(0);
    }
    
    srand(time(NULL));

    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);

    if (n2 > n1-1)
    int n3, i = 1;

    while ((n3 = rand() % n1) != n2) {
        printf("%d\n",n3);
        i++;
    }
    
    printf("%d\nIters: %d\n",n3,i);
    return 0;
}
