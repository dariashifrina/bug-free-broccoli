/*
Team: bug-free-broccoli
Queenie Xiang, Dasha Shifrina 
Systems pd5
HW07: /dev(ise a )/random( plan)
2017-10-29
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h> 
#include <fcntl.h>

int random_num(){
  int rannum;
  int fd = open("/dev/random", O_RDONLY);
  read(fd, &rannum, sizeof(int));

  if(errno){
    printf("Errno: %d\n", errno);
    printf("Error Message: %s\n", strerror(errno));
  }

  close(fd);
  return rannum;
}


int main(){
  int arr1[10];
  printf("Generating random numbers:\n");
  int i;
  for(i = 0; i<10; i++){
    arr1[i] = random_num();
    printf("%d\n",arr1[i]);
  }

  //write array to file
  int fd = open("array", O_WRONLY | O_CREAT | O_EXCL, 0644);
  //printf("writefile: %d\n", writefile);
  //printf("error: %s\n", strerror(errno)); 
  write(fd, arr1, sizeof(arr1));
  close(fd);

  //read file into different array
  int arr2[10];
  int fd_transferfile = open("array", O_RDONLY);

  //printf("fd_transferfile: %d", transferfile);
  read(fd_transferfile, arr2, sizeof(arr2));
  close(fd_transferfile);

  //print content of second arr
  int counter;
  printf("Checking if second array matches:\n");
  for(counter = 0; counter < 10; counter++){
    printf("%d\n", arr2[counter]);
  }
  return 0;
}
