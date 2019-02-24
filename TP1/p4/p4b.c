#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv []) {

    int count = atoi(argv[argc-1]);
   
    for(int i = 0; i < count; i++) {
        printf("Hello");
        for (int k =1; k < (argc-1); k++) {
            printf(" %s", argv[k]);
        }
        printf("!\n");
    }
    
    return 0;
}
