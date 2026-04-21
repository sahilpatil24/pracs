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

  printf("%d ",head);

  //core logic
  //3 tasks - 
  // compute the distance from head and request
  // find the minimum distance
  // get the index -> that index is the request we will be serving in that iteration

  int completed = 0;
  int seek = 0;
  while(completed != n) {
    //computing the distance
    int min = 999, index = 0;
    for(int i = 0; i < n; i++) {
      if(served[i] == -1 && min > abs(req[i] - head)) {
        min = abs(req[i] - head);
        index = i;
      }
    }

      //index is the request we will be serving now
      head = req[index];
      seek += min;
      served[index] = 1;
      printf("%d ",head); 
      completed++;
    } 

  printf("Total head movement: %d",seek);





























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