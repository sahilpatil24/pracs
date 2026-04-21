//c-scan disk scheduling policy

#include<stdio.h>
#include<stdlib.h>

int main() {
  int n;
  printf("Enter the number of requests: ");
  scanf("%d",&n);
  
  int req[n];
  int done[n];
  int cylinders;
  
  for(int i = 0; i < n; i++) {
    printf("Request %d: ",i+1);
    scanf("%d",&req[i]);
    done[i] = 0;
  }
  
  printf("Enter the number of cylinders: ");
  scanf("%d",&cylinders);

  int direction = 0;
  printf("Enter the direction(1 = left, 2 = right): ");
  scanf("%d",&direction);
  
  int head = 0;
  printf("Enter the head: ");
  scanf("%d",&head);


  //core logic
  //sort first
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(req[i] < req[j]) {
        int temp = req[i];
        req[i] = req[j];
        req[j] = temp;
      }
    }
  }

  // printf("Sorted requests: \n");
  // for(int i = 0; i < n; i++) {
  //   printf("%d -> ", req[i]);
  // }

  //then find the split head
  //the first right position next to the head
  //how to find
  int right = 0;
  for(int i = 0; i < n; i++) {
    if(req[i] > head) {
      right = i;
      break;
    }
  }

  printf("\nRight - > %d",right);
  printf("\nStarting from the left: \n");
  int seek = 0;


  if(direction == 1) { //left
    for(int i = right - 1; i >= 0; i--) {
      // printf("%d ",req[i]);
      //traverse from the index till 0
      seek += abs(req[i] - head);
      head = req[i];
      printf("\nSeek Time: %d\nCurrent Head: %d\n",seek,head);
    }
    
    //now go till 0
    // seek += abs(0 - head);
    // head = 0;
    // printf("\nSeek Time: %d\nCurrent Head: %d\n",seek,head);
    
    //now go to cylinder - 1
    seek += abs(head - right);
    head = right;
    printf("\nSeek Time: %d\nCurrent Head: %d\n",seek,head);
    
    for(int i = right; i < n; i++) {
      seek += abs(req[i] - head);
      head = req[i];
      printf("\nSeek Time: %d\nCurrent Head: %d\n",seek,head);
    }
    
    // //now move towards right
    // for(int i = right; i < n; i++) {
    //   seek += abs(req[i] - head);
    //   head = req[i];
    //   printf("\nSeek Time: %d\nCurrent Head: %d\n",seek,head);
    // }
    
    //now go to the end of cylinder - 1
    // seek += abs(head - cylinder - 1);
    // head = req[i];
    // printf("\nSeek Time: %d\nCurrent Head: %d\n",seek,head);

  }
  else { //right

    //if we are traversing from the right
    //then we should start from the right index -> 199 cylinder - 1
    //then we should go the first request not 0
    //in path we still scan the remaining ones

    for(int i = right; i <= n; i++) {
      //now we have the right index
      seek += abs(req[i] - head);
      head = req[i];
      printf("\nSeek Time: %d\nCurrent Head: %d\n",seek,head);
    }

    //now go to cylinder - 1
    seek += abs(head - cylinders - 1);
    head = cylinders - 1;
    printf("\nSeek Time: %d\nCurrent Head: %d\n",seek,head);
    
    //now go to left from the initial head position
    for(int i = right - 1; i >= 0; i--) {
      seek += abs(req[i] - head);
      head = req[i];
      printf("\nSeek Time: %d\nCurrent Head: %d\n",seek,head);
    }
  }


  return 0;
}