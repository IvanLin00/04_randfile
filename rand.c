#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int randint(){
  int i;
  int fd = open("/dev/random",O_RDONLY);
  if (fd>0){
    int n = read(fd,&i,sizeof(i));
    if (n<0) return -1;
    close("/dev/random")
    return i;
  }
  return -1;
}

int main(){
  printf("Generating random numbers:\n");
  int rand_arr[10];
  for (int i = 0; i < 10; i++){
    rand_arr[i] = randint();
    printf("random %d: %d\n", i, rand_arr[i]);
  }

  return 0;
}
