#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_LENGTH 256
#define MAX 50

int main(void) {
    
    FILE *src, *dst;
    char buf[BUF_LENGTH];
    
    if ( ( src = fopen( "infile.txt", "r" ) ) == NULL ) {
        perror("Error opening file");
        printf("Error: %s\n",strerror(errno));
        exit(1);
    }
    
    if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL ) {
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
