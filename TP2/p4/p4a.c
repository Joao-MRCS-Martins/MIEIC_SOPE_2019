#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{

    int fd1, nr, nw;
    unsigned char buffer[BUFFER_SIZE];

    if (argc != 2)
    {
        printf("Usage: %s <file_name> \n", argv[0]);
        exit(1);
    }

    fd1 = open(argv[1], O_WRONLY | O_CREAT | O_EXCL);
    if (fd1 == -1)
    {
        perror(argv[1]);
        exit(2);
    }

    printf("To write to the document, simply type a line at time and press Enter.\nWhen you are done press Enter on a empty line to finish.\n");
    while ((nr = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
    {
        if (nr <= 1)
            break;
        if ((nw = write(fd1, buffer, nr)) <= 0 || nw != nr)
        {
            perror(argv[2]);
            close(fd1);
            exit(3);
        }
    }

    close(fd1);

    exit(0);
}