#include<stdio.h>

int main() {

  int n;

  printf("Enter n: ");
  scanf("%d",&n);

  int process[n];
  int pr[n];
  int done[n];
  int at[n],bt[n],ct[n],tat[n],wt[n];

  //taking input from the user - at and bt
  for(int i = 0; i < n; i++) {
    printf("Enter the arrival time, burst time and the priority for the process %d: ",i+1);
    scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
    done[i] = 0;
  }

  int tat_avg = 0;
  int wt_avg = 0;

  //core logic idea
  //first write a for loop to get the minimum
  //here we need to select a process so once you get the minimum
  //store the process number that has minimum value for pr

  //but we dont know if the process is executed or not
  //create an array to check if the process has been executed
  
  //3 condition - arrival time, minimum value, executed or not
  
  //execution of the process 6 lines of code
  int time = 0;
  for(int i = 0; i < n; i++) {

    //minimum finding loop
    int min = 999;
    int pr_no = -1;
    for(int j = 0; j < n; j++) {
      if(at[j] <= time && min > pr[j] &&  done[j] == 0) {
        min = pr[j];
        pr_no = j;
      }
    }

    //if no process valid selected then time++
    if(pr_no == -1) {time++; i--; continue;}

    //execution part
    time += bt[pr_no];
    ct[pr_no] = time;
    tat[pr_no] = ct[pr_no] - at[pr_no];
    wt[pr_no] = tat[pr_no] - bt[pr_no];
    tat_avg += tat[pr_no];
    wt_avg += wt[pr_no];
    done[pr_no] = 1;

    
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