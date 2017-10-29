#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h> 
#include <fcntl.h>

int random_num(){
  int rannum;
  int place = open("/dev/random", O_RDONLY);
  read(place, &rannum, sizeof(int));
  if(errno){
    printf("Errno: %d\n", errno);
    printf("Error Message: %s\n", strerror(errno));
  }

  close(place);
  return rannum;
}

int main(){
  int blah[10];
  printf("Generating random numbers:\n");
  int i;
  for(i = 0; i<10; i++){
    blah[i] = random_num();
    printf("%d\n",blah[i]);
  }
  //write array to file
  int writefile = open("array", O_WRONLY | O_CREAT);
  write(writefile, blah, sizeof(int) * 10);
  close(writefile);
  //read file into different array
  int wow[10];
  int transferfile = open("array", O_RDONLY);
  read(transferfile, wow, sizeof(int) * 10);
  close(transferfile);
  //print content of second arr
  int counter;
  printf("Checking if second array matches:\n");
  for(counter = 0; counter < 10; counter++){
    printf("%d\n", wow[counter]);
  }
  return 0;
}
