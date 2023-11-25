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
  int priority;
};

int main(){
    FILE* fp = fopen("priority_input.txt", "r");

    int process_count = 0;
    fscanf(fp, "%d", &process_count);

    struct Process processes[process_count+1];
    // storing Arrival time
    for (int i = 0; i < process_count; i++) {
      int temp;
      fscanf(fp, "%d", &temp);
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

    // storing Priority
    for (int i = 0; i < process_count; i++) {
      int temp;
      fscanf(fp, "%d", &temp);
      processes[i].priority = temp;
     // printf("\n%d ", processes[i].burst_time);
    }



   int process_done=0;
   int current_time;
   int min_process=process_count;
   processes[min_process].priority=1000;
   for(int i = 0; process_count!=process_done; i++){
    for(int t = 0; t < process_count; t++){
       if((processes[min_process].priority>processes[t].priority) &&  (processes[t].remaining_burst_time>0) && (processes[t].arrival_time<=i)){
                min_process=t;
       }
    }

  // printf("\n process%d %d ",min_process, processes[min_process].remaining_burst_time);
   processes[min_process].remaining_burst_time=processes[min_process].remaining_burst_time-1;
   if (processes[min_process].remaining_burst_time==0){
        process_done=process_done+1;
        current_time=i+1;
        processes[min_process].turnarround_time=current_time-processes[min_process].arrival_time;
        processes[min_process].waitting_time=processes[min_process].turnarround_time-processes[min_process].burst_time;
        processes[min_process].completion_time=current_time;
        current_time=0;
        min_process=process_count;
}
}
 for(int t = 0; t < process_count; t++){
        printf("Process%d: completiontime:%d Waitingtime: %d Turnaround time: %d\n",t+1,processes[t].completion_time,processes[t].waitting_time, processes[t].turnarround_time);
 }
return 0;
}
