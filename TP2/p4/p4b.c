#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


#define BUFFER_SIZE 512
#define MAX_LEN 50

struct Student {
    char* name;
    int grade;
};

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

    struct Student new_stud;
    new_stud.name = malloc(MAX_LEN);

    printf("To write to the document, simply type a line at time and press Enter.\nWhen you are done press Enter on a empty line to finish.\n");
    while ((nr = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
    {
        if (nr <= 1)
            break;
        new_stud.name = buffer;
        if(read(STDIN_FILENO,buffer,BUFFER_SIZE)) {
            new_stud.grade = atoi(buffer);
            if ((write(fd1, new_stud.name, strlen(new_stud.name)) <= 0)) {
                perror(argv[2]);
                close(fd1);
                exit(3);
            }
        }
    }

    close(fd1);
    exit(0);
}