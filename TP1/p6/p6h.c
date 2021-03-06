#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_LENGTH 256
#define MAX 50

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: <executable> <file1> <file2>\n");
        exit(1);
    }

    FILE *src, *dst;
    char buf[BUF_LENGTH];
    
    if ( ( src = fopen( argv[1], "r" ) ) == NULL ) {
        perror("Error opening file");
        printf("Error: %s\n",strerror(errno));
        exit(1);
    }
    
    if ( ( dst = fopen( argv[2], "w" ) ) == NULL ) {
        perror("Error opening file");
        printf("Error: %s\n",strerror(errno));
        exit(2);
    }
    
    while( ( fgets( buf, MAX, src ) ) != NULL ) {
        fputs( buf, dst );
    }
    fclose( src );
    fclose( dst );
    exit(0); // zero é geralmente indicativo de "sucesso"
}