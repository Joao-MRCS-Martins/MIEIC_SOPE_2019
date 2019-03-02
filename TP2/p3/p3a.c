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

  if (argc != 2) {
    printf("Usage: %s <file_name> \n", argv[0]);
    exit(1);
  }
  
  fd1 = open(argv[1], O_RDONLY);
  if (fd1 == -1) {
    perror(argv[1]);
    exit(2);
  }

  while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0) {
    if ((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nw != nr) {
      perror(argv[2]);
      close(fd1);
      exit(3);
    }
  }

  write(STDOUT_FILENO,"\n",1);
  close(fd1);

  exit(0);
}