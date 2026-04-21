#include<stdio.h>

int main() {

  int n;

  printf("Enter n: ");
  scanf("%d",&n);

  int process[n];
  int at[n],bt[n],ct[n],tat[n],wt[n];

  //taking input from the user - at and bt
  for(int i = 0; i < n; i++) {
    printf("Enter the arrival time and burst time for the process %d: ",i+1);
    scanf("%d %d",&at[i],&bt[i]);
  }

  //core logic
  //create a variable named time
  int time = 0;
  int tat_avg = 0;
  int wt_avg = 0;
  //for every process do 
  //first increment the current time with burst time
  //time = bt[i]
  //completion time update with the current time
  //then formulas 
  //tat = ct - at
  //wt = tat - bt
  //average

  for(int i = 0; i < n; i++) {
    time += bt[i];
    ct[i] = time;
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    tat_avg += tat[i];
    wt_avg += wt[i];
  }

  //displaying the output
  printf("displaying the output: \n");
  printf("Pi \t AT \t BT \t WT \t CT \t TAT \t \n");
  for(int i = 0; i < n; i++) {
    printf("p%d \t %d \t %d \t %d \t %d \t %d \t \n",i+1,at[i],bt[i],wt[i],ct[i],tat[i]);

    
  }

  printf("avgerage tat: %d\n",tat_avg/n);
  printf("avgerage wt: %d",wt_avg/n);

  return 0;
}