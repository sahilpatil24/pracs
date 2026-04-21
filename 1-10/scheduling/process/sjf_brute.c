#include<stdio.h>

int main() {

  int n;

  printf("Enter n: ");
  scanf("%d",&n);

  int process[n];
  // int pr[n];
  int at[n],bt[n],ct[n],tat[n],wt[n];

  //taking input from the user - at and bt
  for(int i = 0; i < n; i++) {
    printf("Enter the arrival time, burst time for the process %d: ",i+1);
    scanf("%d %d",&at[i],&bt[i]);
  }

  int tat_avg = 0;
  int wt_avg = 0;

  //core logic
  //why not just sort based on the burst time
  for(int i = 0; i < n; i++) {
    //sorting
    for(int j = 0; j < n; j++) {
      if(bt[i] < bt[j]) {int temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;}
    }
  }
  
  int time = 0;
  for(int i = 0; i < n; i++) {
  //sorted now execute
  if(at[i] <= time) {
    time += bt[i];
    ct[i] = time;
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    tat_avg += tat[i];
    wt_avg += wt[i];
  }
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