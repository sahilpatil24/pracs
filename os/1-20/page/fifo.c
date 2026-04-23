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
  int page_seq[p],frames[f];
  printf("Enter the page sequence one by one:");
  for(int i = 0; i < p; i++) {
    printf("\nPage Numberv %d: ",i);
    scanf("%d",&page_seq[i]);
  }

  //frame array initialize to -1 i.e. empty
  for(int i = 0; i < f; i++) {
    frames[i] = -1;
  }

  //core logic
  //traverse through the pages one by one in page sequence
  //if found in the frame then found = 1 else 0
  int faults = 0,index = 0;
  for(int i = 0; i < p; i++) {
    int found = 0;

    for(int j = 0; j < f; j++) {
      //if frame has the current required page then
      if(frames[j] == page_seq[i]) {
        //page found
        found = 1;
        break;
      }
    }

    if(!found) {
      //if the page is not found then bring that page into the frame
      frames[index] = page_seq[i];
      index = (index + 1) % f;
      faults++;
    }
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