#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
  int fd;
  char *text1="AAAAA";
  char *text2="BBBBB";

  if((fd = open("f1.txt",O_CREAT|O_WRONLY|O_SYNC|O_APPEND,0600)) == -1) {
    perror("file");
    exit(1);
  }

  getchar();
  if(write(fd,text1,5) == -1) {
    perror("file");
    exit(2);
  }

  if(write(fd,text2,5) == -1) {
    perror("file");
    exit(3);
  }

  if(close(fd) == -1) {
    perror("file");
    exit(4);
  }
  exit(0);
}

