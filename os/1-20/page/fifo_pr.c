#include<stdio.h>

int main() {
  //input no of pages and frame
  int f,p;
  printf("Enter the number of frames:");
  scanf("%d",&f);

  printf("Enter the number of pages:");
  scanf("%d",&p);

  //create page and frame arrays
  int page_seq[p],frames[f];
  printf("Enter the page sequence:");
  for(int i = 0; i < p; i++) {
    printf("Page Number %d: ",i+1);
    scanf("%d",&page_seq[i]);
  }

   for(int i = 0; i < f; i++) {
      frames[i] = -1;
    }

  //core logic
  //traverse through the pages one by one

  //first fill the f pages into the frame logic
  int faults = 0;
  int index = 0;
  //now calculate page hit and page miss
  for(int i = 0; i < p; i++) {
    int found = 0;
    
    //find the current page page_seq[i] in the frames array
    //if found then found = 1 else found = 0
    
    for(int j = 0; j < f; j++) {
      if(page_seq[i] == frames[j]) {
        found = 1;
        break;
      }
    }

    
    
    if(!found) {
      frames[index] = page_seq[i];
      index = (index + 1) % f;
      faults++;
    }

    printf("\nIteration: %d\tt",i);
    printf("The frames: ");
    
    for(int i = 0; i < f; i++) {
      printf("%d ",frames[i]);      
    }

    printf(" Faults: %d",faults);
  }

  printf("Page faults: %d\n",faults);

  return 0;
}