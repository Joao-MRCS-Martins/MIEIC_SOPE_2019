#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[]) {

    char * user = malloc(20*sizeof(char));

    int i = 0;
    while (envp[i] != NULL) {
        if(strncmp(envp[i],"USER",4) == 0) {
            strncpy(user,envp[i]+5,20);
        }
        i++;
    }

    printf("Hello %s!\n",user);
    free(user);
    return 0;
}
