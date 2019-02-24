#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    time_t t;
    srand((unsigned) time(&t));
    struct tms time_info;
    int ticks_seg = sysconf(_SC_CLK_TCK);
    times(&time_info);
    
    if (argc != 3) {
        printf("Usage: <executable> <n1> <n2>\n");
        exit(0);
    }
    
    

    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    int n3, i = 1;

    printf("Initial time: user - %d, system - %d\n",time_info.tms_utime/ticks_seg,time_info.tms_stime/ticks_seg);
    while ((n3 = rand() % n1) != n2) {
        printf("%d\n",n3);
        i++;
    }
    
    printf("%d\nIters: %d\n",n3,i);
    printf("Final time: user - %d, system - %d\n",time_info.tms_utime/ticks_seg,time_info.tms_stime/ticks_seg);
    return 0;
}