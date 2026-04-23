#include<stdio.h>

int main() {
  int n = 5;
  int wt[n],tat[n],bt[n];
  float average_tat = 0, average_wt = 0;
  
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  
  printf("Enter the burst time for the processes: ");
  for(int i = 1; i <= n; i++) {
    scanf("%d", &bt[i]);
  }
  
  //core logic
  //wt = w[i-1] + bt[i-1]
  for(int i = 1; i <= n; i++) {
    wt[i] = wt[i-1] + bt[i-1];
    tat[i] = wt[i] + bt[i];
    average_wt += wt[i];
    average_tat += tat[i];
  }

  //average calculation
  printf("The average waiting time is: %.2f",average_tat/n);
  printf("The average tat is: %.2f",average_wt/n);



  printf("\nThe table is: \n");
  printf("pi\tbt\twt\ttat\n");
  for(int i = 1; i <= n; i++) {
    // printf("p%d\tb[%d]\tw[%d]\ttat[%d]\n",i,i,i,i);
    printf("p%d\t%d\t%d\t%d\n",i,bt[i],wt[i],tat[i]);
  }
  
  return 0;

}

/*
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int wt[n], tat[n], bt[n];

    printf("Enter the burst time for the processes:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Core logic (FCFS)
    wt[0] = 0;

    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    float average_wt = 0, average_tat = 0;

    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        average_wt += wt[i];
        average_tat += tat[i];
    }

    // Average calculation
    printf("\nThe average waiting time is: %.2f", average_wt / n);
    printf("\nThe average turnaround time is: %.2f", average_tat / n);

    // Table output
    printf("\n\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    return 0;
}


*/