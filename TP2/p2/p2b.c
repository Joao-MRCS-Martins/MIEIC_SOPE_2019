//FOLHA 2 - p2b.c & p2c
//FILE COPY
//USAGE: copy source destination

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

//p2c include files
#include <time.h>
#include <sys/times.h>
#include <unistd.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
  //p2c - time measuring/////////////////
  time_t t;                            //
  srand((unsigned) time(&t));          //
  struct tms time_info;                //
  int ticks_seg = sysconf(_SC_CLK_TCK);//
  times(&time_info);                   //
  ///////////////////////////////////////

  int fd1, fd2, nr, nw;
  unsigned char buffer[BUFFER_SIZE];

  if (argc != 3) {
    printf("Usage: %s <source> <destination>\n", argv[0]);
    return 1;
  }

  //p2c - time measuring
  printf("Initial time: user - %d, system - %d\n",time_info.tms_utime/ticks_seg,time_info.tms_stime/ticks_seg);
    
  fd1 = open(argv[1], O_RDONLY);
  if (fd1 == -1) {
    perror(argv[1]);
    return 2;
  }
  fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);
  if (fd2 == -1) {
    perror(argv[2]);
    close(fd1);
    return 3;
  }
  while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0) {
    if ((nw = write(fd2, buffer, nr)) <= 0 || nw != nr) {
      perror(argv[2]);
      close(fd1);
      close(fd2);
      return 4;
    }
  }
  close(fd1);
  close(fd2);

  //p2c - time measuring
  printf("Final time: user - %d, system - %d\n",time_info.tms_utime/ticks_seg,time_info.tms_stime/ticks_seg);
  
  return 0;
}

