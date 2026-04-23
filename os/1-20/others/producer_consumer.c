// Write a C program to implement solution of Producer consumer problem through
// Semaphore.
#include<stdio.h>
#include<stdlib.h>

//global variables
#define N 5
int buffer[N];
int in = 0;
int out = 0;
int x = 0;

int empty = N; //initially the entire buffer is empty
int full = 0;
int mutex = 1; 

//to avoid race conditions
void wait(int *s) {
  if((*s) <= 0) {} //if s == 0 then wait till s != 0
  else {            //decrement s which means that a process is now in its critical section
    (*s)--;
  }
}

void signal(int *s) {
  (*s)++;
}

//PECF
//functions
void produce() {

  if(empty == 0)  {
    printf("Buffer full cant produce more items"); 
    return;
  }
  
  int item = ++x;
  //2 functions
  wait(&empty);
  wait(&mutex);
  
  buffer[in] = item;
  printf("\nItem %d produced at position %d",item, in);
  in = (in + 1) % N;

  //2 functions
  signal(&mutex);
  signal(&full);
  
}
void consume() {
  //2 functions
  wait(&full);
  wait(&mutex);
  
  int item = buffer[out];
  printf("\nItem %d was consumed from position %d",item,out);
  out = (out + 1) % N;
  
  //2 functions
  signal(&mutex);
  signal(&empty);

}


//main function
int main() {
  
  int choice = 0;
  int produced;
  while(choice != 4) {
    printf("\n\nEnter a choice from 1 to 3:");
    printf("\n1. Produce an item");
    printf("\n2. Consume an item");
    printf("\n3. Display the buffer");
    printf("\n4. Exit");
    scanf("%d",&choice);
    
    //call the functions one by one in switch case
    switch(choice) {
      case 1:
        produce();
        break;
      case 2:
        consume();
        printf("\nItem that was consumed: ");        
        break;
      case 3:
        // display();
        printf("\nDisplaying the buffer");
        printf("");
        break;
      case 4:
        printf("Exit done");
        return 0;
    }
  }

  return 0;
}