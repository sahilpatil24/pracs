//best fit
#include<stdio.h>
int main() {

  int nb,np;
  printf("Enter the number of blocks: ");
  scanf("%d",&nb);

  printf("Enter the number of processes: ");
  scanf("%d",&np);

  int block[nb],process[np];

  for(int i = 0; i < nb;i++) {
    printf("\nEnter the size of block %d: ",i+1);
    scanf("%d",&block[i]);
  }

  for(int i = 0; i < np;i++) {
    printf("\nEnter the size of process %d: ",i+1);
    scanf("%d",&process[i]);
  }

  //input done

  //core logic
  // for(int i = 0; i < np;i++) {
  //   int best = -1; //no block is currently selected
  //   //best = -1

  //   for(int j = 0; j < nb; j++) {
  //     if(block[j] >= process[i]) {
  //       if(best == -1 || block[best] > block[j])  {
  //         //2 conditions 1 -> block is big enough to fit in the process 
  //         // 2 -> block which is previously selected is larger than current one
  //         best = j;
  //       }
  //     }
  //   }
  // }

  int allocation[np];
  //core logic implementation
  for(int i = 0; i < np; i++) {
    int best = -1;

    for(int j = 0; j < nb; j++) {
      if(block[j] >= process[i]) {
        if(best = -1 || block[best] > block[j]) {
          best = j;
        }
      }
    }

    if(best != -1) {
      allocation[i] = best;
      block[best] -= process[i];
    }
  }
  

  //printing work
  for(int i = 0; i < nb;i++) {
    printf("\nThe size of block %d: %d",i+1,block[i]);
  }

  printf("\nThe allocated block per process:");
  for(int i = 0; i < np;i++) {
    printf("\nProcess %d: %d",i+1,allocation[i]);
  }


  return 0;
}