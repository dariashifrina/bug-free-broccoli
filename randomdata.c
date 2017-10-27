#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int random_num(){
  int rannum = open("/dev/random", "O_RDONLY", 111);
  return rannum;
}

int main(){
  int blah[10];
  printf("Generating random numbers:\n");
  int i;
  for(i = 0; i<10; i++){
    int wow = random_num();
    blah[i] = wow;
    printf("random %d: %d\n", i, wow);
  }
  //write array to file
  //read file into different array
  int wow[10];
  //print content of second arr
  return 0;
}
