//sstf
// Write a program to implement the SSTF Disk Scheduling Policy
#include<stdio.h>
#include<stdlib.h>
int main() {
  //input
  ///disk requests, initial head position, 
  int n = 0;
  printf("Enter the number of requests: ");
  scanf("%d",&n);
  
  int served[n],req[n];
  printf("Enter the disk requests: \n");
  for(int i = 0; i < n; i++) {
    printf("\nrequest %d: ", i+1);
    scanf("%d",&req[i]);
    served[i] = -1;
  }
  int head = 0;
  printf("Enter the inital head position: ");
  scanf("%d",&head);
  
  int cylinder = 0;
  printf("Enter the cylinder count: ");
  scanf("%d",&cylinder);

  //first sort
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(req[i] < req[j]) {
        int temp = req[i];
        req[i] = req[j];
        req[j] = temp;
      }
    }
  }


  //sorting done now 
  // ask for the direction
  int dir = 0;
  printf("Enter 1 or 2: ");
  scanf("%d",&dir);
  
  //find the right split
  //find the index before which the head lies
  int min = 999, right = 0;
  for(int i = 0; i < n; i++) {
    if(head < req[i]) {right = i; break;}
  }

  //if direction = 1 then left or 2 = right
  if(dir == 1) {
    //left
    //move from the right split to 0
    printf("\n\nright is -> %d and %d", req[right], right);
    int seek = 0;
    for(int i = right - 1; i >= 0; i--) {
      seek += abs(req[i] - head);
      head = req[i];
      printf("\nSeek time is %d\nHead is %d\n",seek,head);
    }
    
    //touch 0
    seek += abs(0 - head);
    head = 0;
    printf("\nSeek time is %d\nHead is %d\n",seek,head);
    
    for(int i = right; i < n; i++) {
      seek += abs(req[i] - head);
      head = req[i];
      printf("\nSeek time is %d\nHead is %d\n",seek,head);
    }





  }
  else {
    //right
    //move from the 199 to first req
    printf("\n\nright is -> %d and %d", req[right], right);
    int seek = 0;
     for(int i = right; i < n; i++) {
      seek += abs(req[i] - head);
      head = req[i];
      printf("\nSeek time is %d\nHead is %d\n",seek,head);
    }

    
    
    //touch 0
    seek += abs(head - (cylinder - 1));
    head = cylinder - 1;
    printf("\nSeek time is %d\nHead is %d\n",seek,head);
    
   
    for(int i = n - 1; i >= 0; i--) {
      seek += abs(req[i] - head);
      head = req[i];
      printf("\nSeek time is %d\nHead is %d\n",seek,head);
    } 
    
  }











  // int dist[n];
  // while(completed != n) {

  //   //finding the distance
  //   for(int i = 0; i < n; i++) {
  //     if(served[i] == -1) {
  //       dist[i] = abs(req[i] - head);
  //     }
  //     else {
  //       dist[i] = 999;
  //     }
  //   }
    
  //   //finding the minimum distance
  //   int min = 999, index = 0;
  //   for(int j = 0; j < n; j++) { 
  //     if(min > dist[j]) { 
  //       min = dist[j];
  //       index = j;
  //     }
  //   } 
    
  // }

// 8
// 176 79 34 60 92 11 41 114
// 50
// ans 204
}