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
    if (n<0){
		printf("error %d: %s\n", errno, strerror(errno));
		return -1;
	}
    close("/dev/random");
    return i;
  }
  else{
	  printf("error %d: %s\n", errno, strerror(errno));
	  return 0;
  }
}

int main(){
  printf("Generating random numbers:\n");
  int rand_arr[10], read_arr[10];
  for (int i = 0; i < 10; i++){
    rand_arr[i] = randint();
    printf("random %d: %d\n", i, rand_arr[i]);
  }
  printf("Writing files to file...\n");
  int fd = open("random_numbers", O_RDWR | O_CREAT, 0666);
  if (fd < 0){
	  printf("error %d: %s\n", errno, strerror(errno));
	  return 0;
  }
  fd = write(fd, rand_arr, sizeof(rand_arr));
  if (fd < 0){
	  printf("error %d: %s\n", errno, strerror(errno));
	  return 0;
  }
  fd = close("random numbers");
  if (fd < 0){
	  printf("error %d: %s\n", errno, strerror(errno));
	  return 0;
  }
  printf("Reading numbers from file...\n");
  fd = open("random_numbers", O_RDONLY);
  if (fd < 0){
	  printf("error %d: %s\n", errno, strerror(errno));
	  return 0;
  }
  fd = read(fd, read_arr, sizeof(rand_arr));
  if (fd < 0){
	  printf("error %d: %s\n", errno, strerror(errno));
	  return 0;
  }
  fd = close("random numbers");
	if (fd < 0){
	  printf("error %d: %s\n", errno, strerror(errno));
	  return 0;
	}
  printf("Verification that written values were the same:\n");
  for (int i = 0; i < 10; i++){
	  printf("random %d: %d\n", i, read_arr[i]);
  }
  return 0;
}
