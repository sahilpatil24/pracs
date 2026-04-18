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
    printf("Block %d",i+1);
    scanf("%d", &block[i]);
  }

  printf("\nEnter the sizes of processes one by one: ");
  for(int i = 0; i < np; i++) {
    printf("Process %d",i+1);
    scanf("%d", &process[i]);
  }

  int allocation[np];
  //core logic
  for(int i = 0; i < np; i++) { //for every process
    //initialize best = -1 meaning that no suitable best block is yet found for ith process
    int best = -1;

    for(int j = 0; j < nb; j++) { 
      //for every block check if the size of this block is large enough to fit the process size
      if(block[j] >= process[i]) {
        if(best = -1 || block[best] < block[j]) //if no suitable block is found or the best block is larger than the current block then we allocate the current block as the best block
          best = j;
      }
    }


    //once all the blocks are checked
    if(best != -1) { //means that the largest block is found then
       allocation[i] = best;
       block[best] -= process[i];
    }
 
  }

  printf("\nThe block sizes current: ");
  for(int i = 0; i < nb;i++) {
    printf("block %d: %d",i+1,block[i]);
  }

  printf("\nThe allocated blocks: ");
  for(int i = 0; i < np;i++) {
    printf("Process %d: %d",i+1,allocation[i]);
  }

  return 0;
}