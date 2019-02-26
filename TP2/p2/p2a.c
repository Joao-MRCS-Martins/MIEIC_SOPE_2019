#include <stdio.h>
#include <stdlib.h>

#define BUF_LENGTH 256
#define MAX 50

int main(int argc, char* argv[]) {
    

    if(argc != 3) {
        printf("Usage: copy <source> <destination>\n");
        exit(1);
    }

    FILE *src, *dst;
    char buf[BUF_LENGTH];
    
    if ( ( src = fopen( argv[1], "r" ) ) == NULL ) {
        exit(1);
    }
    
    if ( ( dst = fopen( argv[2], "w" ) ) == NULL ) {
        exit(2);
    }
    size_t nr=0;
    while((nr = fread( buf, 1, BUF_LENGTH, src)) >0) {
        int nw = fwrite(buf, 1, nr,dst);
        printf("nw: %d\t nr: %d\n",nw,nr);
    }

    fclose( src );
    fclose( dst );
    exit(0); // zero é geralmente indicativo de "sucesso"
}
