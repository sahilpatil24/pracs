#include<stdio.h>
#include<stdlib.h>

//variables and functions
const int n = 5;
int buffer[5];
int in = 0, out = 0;
int x = 0;

//semaphore variables
int empty = n;
int full = 0;
int mutex = 1;

void wait(int *s) {
  if((*s) <= 0) {
    //busy waiting
  }
  else {
    (*s)--;
  }
}

void signal(int *s) {
  (*s)++;
}

//other functions
void produce() {
  if(full == n) {
    printf("\nBuffer is full! cant produce any items");
    return;
  }

  //algo
  wait(&empty);
  wait(&mutex);

  int item = ++x;
  buffer[in] = item;
  printf("\nItem %d produced at position: %d",item,in);
  in = (in + 1) % n;

  signal(&full);
  signal(&mutex);

}
void consume() {
    if(empty == n) {
    printf("\nBuffer is empty! cant consume any items");
    return;
  }

  //algo
  wait(&full);
  wait(&mutex);

  int item = buffer[out];
  buffer[out] = 0;
  printf("\nItem %d consumed from position: %d",item,out);
  out = (out + 1) % n;

  signal(&empty);
  signal(&mutex);

}

void display() {
  printf("\nDsiplaying the buffer: ");
  for(int i = 0; i < n; i++) {
    printf("\n%d ", buffer[i]);
  }
};




int main() {
  int choice = 0;
  while(1) {
    printf("\nEnter a value: ");
    scanf("%d",&choice);
    printf("\n1. Produce");
    printf("\n2. Consume");
    printf("\n3. Display buffer");
    printf("\n4. Exit");

    switch(choice) {
      case 1:
        produce();
        break;
      case 2:
        consume();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
      default: 
        printf("\nEnter a valid input:");
        break;
    }
  }

  return 0;
}