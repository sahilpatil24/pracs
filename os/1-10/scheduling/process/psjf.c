#include<stdio.h>

//to make this preemptive we have to make 2 changes
//we normally do time += bt[i]
//but here we do time++; and then bt[i]--
//which means only increment time and then reduce the burst time by 1

//2. normally we directly mark a process as done after the execution
//but here mark it done only when bt[i] == 0
//which means the process has been actually completed its execution

int main() {

  int n;

  printf("Enter n: ");
  scanf("%d",&n);

  int process[n];
  int pr[n];
  int done[n];
  int at[n],bt[n],ct[n],tat[n],wt[n];
  int or_bt[n];

  //taking input from the user - at and bt
  for(int i = 0; i < n; i++) {
    printf("Enter the arrival time, burst time and the priority for the process %d: ",i+1);
    scanf("%d %d",&at[i],&bt[i]);
    or_bt[i] = bt[i];
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
  int completed = 0;
  while(completed < n) {
      
      //minimum finding loop
      int min = 999;
      int pr_no = -1;
      for(int j = 0; j < n; j++) {
        if(at[j] <= time && min > bt[j] &&  done[j] == 0) {
          min = bt[j];
          pr_no = j;
        }
      }
      
      //if no process valid selected then time++
      if(pr_no == -1) {time++; continue;}
      
      //execution part
      // time += bt[pr_no];
      time++;
      bt[pr_no]--;
      printf("\ntime %d, process in exec: %d",time,pr_no);
      
      if(bt[pr_no] == 0) {
        ct[pr_no] = time;
        tat[pr_no] = ct[pr_no] - at[pr_no];
        wt[pr_no] = tat[pr_no] - or_bt[pr_no];
        tat_avg += tat[pr_no];
        wt_avg += wt[pr_no];
        done[pr_no] = 1;
        completed++;
        
      }
      
    
  }
    


  //displaying the output
  printf("displaying the output: \n");
  printf("Pi \t AT \t BT \t WT \t CT \t TAT \t \n");
  for(int i = 0; i < n; i++) {
    printf("p%d \t %d \t %d \t %d \t %d \t %d \t \n",i+1,at[i],or_bt[i],wt[i],ct[i],tat[i]);

    
  }

  printf("avgerage tat: %d\n",tat_avg/n);
  printf("avgerage wt: %d",wt_avg/n);

  return 0;
}