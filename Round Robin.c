#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process{
  int burst_time;
  int arrival_time;
  int turnarround_time;
  int waitting_time;
  int completion_time;
  int remaining_burst_time;
};

int main(){
    FILE* fp = fopen("robin_input.txt", "r");

    int process_count = 0;
    fscanf(fp, "%d", &process_count);
    int quantum_time=0;
    fscanf(fp, "%d", &quantum_time);

    struct Process processes[process_count+1];

    //Storing Arrival time
    for (int i = 0; i < process_count; i++) {
      int temp =0;
      //fscanf(fp, "%d", &temp);
      processes[i].arrival_time = temp;
      //printf("%d ", processes[i].arrival_time);
    }

    // storing Burst time & Remaining Burst time
    for (int i = 0; i < process_count; i++) {
      int temp;
      fscanf(fp, "%d", &temp);
      processes[i].burst_time = temp;
      processes[i].remaining_burst_time = temp;
     // printf("\n%d ", processes[i].burst_time);
    }



   int process_done=0;
   int current_time=0;
   int flag=0;


   for(int i = 0; process_count!=process_done;){  // Gratt chart current_time

      if(processes[i].remaining_burst_time <= quantum_time && processes[i].remaining_burst_time > 0){
        //sum = sum + remain[i];
        current_time=current_time+ processes[i].remaining_burst_time;
        processes[i].remaining_burst_time= 0;
        flag=1;
        }
     else if (processes[i].remaining_burst_time> quantum_time){
        current_time=current_time+quantum_time;
        processes[i].remaining_burst_time=processes[i].remaining_burst_time-quantum_time;

     }

  // printf("\n process%d %d ",min_process, processes[min_process].remaining_burst_time);

   if (processes[i].remaining_burst_time==0 && flag==1){

        process_done=process_done+1;

        processes[i].completion_time=current_time;
        processes[i].turnarround_time=current_time-processes[i].arrival_time;
        processes[i].waitting_time=processes[i].turnarround_time-processes[i].burst_time;
        flag=0;
}

if(i==process_count-1)
{
i=0;
}
else if(processes[i+1].arrival_time<=current_time)
{
i++;
}
else
{
i=0;
}

}
 for(int t = 0; t < process_count; t++){
        printf("Process%d: completiontime:%d Waitingtime: %d Turnaround time: %d\n",t+1,processes[t].completion_time,processes[t].waitting_time, processes[t].turnarround_time);
 }
return 0;
}
