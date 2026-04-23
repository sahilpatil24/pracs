#include<stdio.h>

// 11: 12
int main() {

  int nb,np;

  printf("Enter the number of blocks: ");
  scanf("%d", &nb);
  printf("Enter the number of prcoess: ");
  scanf("%d", &np);

  int block[nb],process[np];
  printf("\nEnter the sizes of blocks one by one: ");
  for(int i = 0; i < nb; i++) {
    printf("Block %d: ",i+1);
    scanf("%d", &block[i]);
  }

  printf("\nEnter the sizes of processes one by one: ");
  for(int i = 0; i < np; i++) {
    printf("Process %d: ",i+1);
    scanf("%d", &process[i]);
  }


  //first fit
  int allocation[np];

  for(int i = 0; i < np; i++) {
    for(int j = 0; j < nb; j++) {
      if(block[j] >= process[i]) {
        //allocation part
        allocation[i] = j;
        
        //reduction part
        block[j] -= process[i];

        break;
      }
    }
  }

  // int last = 0;
  // int allocation[np];

  // for(int i = 0; i < np; i++) {
  //   int allocated = 0;
  //   for(int j = 0; i < nb; j++) {
  //     int index = (last + j) % nb;
  //     if(block[index] >= process[i]) {
  //       allocated = 1;
  //       block[index] -= process[i];
  //       allocation[i] = index;

  //     }
  //   }
  // }

  /*
  For each process:
    Start searching from last allocated block
    Check all blocks in circular order
    Allocate the first one that fits
    Update last position
  */

  printf("\nThe block sizes current: ");
  for(int i = 0; i < nb;i++) {
    printf("\nblock %d: %d",i+1,block[i]);
  }

  printf("\nThe allocated blocks: ");
  for(int i = 0; i < np;i++) {
    printf("\nProcess %d: %d",i+1,allocation[i]+1);
  }

  return 0;
}