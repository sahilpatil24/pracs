#include<stdio.h>

//2: 51
int main() {
  //input
  //frames and array input count
  int f,p;
  printf("Enter the number of frames: ");
  scanf("%d",&f);
  printf("Enter the number of pages: ");
  scanf("%d",&p);

  //frames and pages array 
  int page_seq[p],frames[f],lru_frame[f];
  printf("Enter the page sequence one by one:");
  for(int i = 0; i < p; i++) {
    printf("\nPage Numberv %d: ",i);
    scanf("%d",&page_seq[i]);
  }

  //frame array initialize to -1 i.e. empty
  for(int i = 0; i < f; i++) {
    frames[i] = -1;
    lru_frame[i] = -1;
  }

  //core logic
  int faults = 0;



    printf("\nIteration: %d\tt",i);
    printf("The frames: ");
    
    for(int i = 0; i < f; i++) {
      printf("%d ",frames[i]);      
    }

    printf(" Faults: %d\n",faults);
  
  }

  printf("faults: %d",faults);

  return 0;
}