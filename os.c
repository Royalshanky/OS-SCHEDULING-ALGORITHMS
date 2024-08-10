#include <stdio.h>
 // here we are going to code for shortest job first scheduling
void SJFscheduling()
{
      int arrival_time[10], burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("Enter the Total Number of Processes: ");
      scanf("%d", &limit); 
      printf("Enter Details of %d Processesn \n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("Enter Arrival Time: ");
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time: ");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      average_waiting_time = wait_time / limit; 
      average_turnaround_time = turnaround_time / limit;
      printf("Average Waiting Time:  %lf \n", average_waiting_time);
      printf("Average Turnaround Time: %lf \n", average_turnaround_time);

}
 //it is code of priority scheduling
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
// here we are going to code for priority scheduling algorithm  
void Priorityscheduling()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    int burst[n],priority[n],index[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
        scanf("%d %d",&burst[i],&priority[i]);
        index[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        int ptemp=priority[i],m=i;
 
        for(int j=i;j<n;j++)
        {
            if(priority[j] > ptemp)
            {
                ptemp=priority[j];
                m=j;
            }
        }
 //swaping accordiing to the priority
        swap(&priority[i], &priority[m]);
        swap(&burst[i], &burst[m]);
        swap(&index[i],&index[m]);
    }
 
    int t=0;
 
    printf("Order of process Execution is\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d is executed from %d to %d\n",index[i],t,t+burst[i]);
        t+=burst[i];
    }
    printf("\n");
    printf("Process Id\tBurst Time\tWait Time\n");
    int wait_time=0;
    int total_wait_time = 0;
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t%d\n",index[i],burst[i],wait_time);
        total_wait_time += wait_time;
        wait_time += burst[i];
    }
    //here we code for average waiting time
    float avg_wait_time = (float) total_wait_time / n;
    printf("Average waiting time is %f\n", avg_wait_time);
    
    int total_Turn_Around = 0;
    for(int i=0; i < n; i++){
        total_Turn_Around += burst[i];
    }
    //find average turn around time
    float avg_Turn_Around = (float) total_Turn_Around / n;
    printf("Average TurnAround Time is %f \n",avg_Turn_Around);

}
//here we code for robin round algorithm
 void Roundrobinscheduling()
{
 
  int cnt,j,n,t,remain,flag=0,tq;
  int wt=0,tat=0,at[10],bt[10],rt[10];
  printf("Enter Total Process: ");
  scanf("%d",&n);
  remain=n;
  for(cnt=0;cnt<n;cnt++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",cnt+1);
    scanf("%d",&at[cnt]);
    scanf("%d",&bt[cnt]);
    rt[cnt]=bt[cnt];
  }
  printf("Enter Time Quantum: ");
  scanf("%d",&tq);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(t=0,cnt=0;remain!=0;)
  {
    if(rt[cnt]<=tq && rt[cnt]>0)
    {
      t+=rt[cnt];
      rt[cnt]=0;
      flag=1;
    }
    else if(rt[cnt]>0)
    {
      rt[cnt]-=tq;
      t+=tq;
    }
    if(rt[cnt]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",cnt+1,t-at[cnt],t-at[cnt]-bt[cnt]);
      wt+=t-at[cnt]-bt[cnt];
      tat+=t-at[cnt];
      flag=0;
    }
    if(cnt==n-1)
      cnt=0;
    else if(at[cnt+1]<=t)
      cnt++;
    else
      cnt=0;
  }
  printf("\nAverage Waiting Time= %f \n",wt*1.0/n);
  printf("Avg Turnaround Time = %f \n ",tat*1.0/n);
  
}


int main()
{
	printf("\n ---------------------------------------------------------------------------------------\n");
	printf("implement the shortest job first scheduling with pre-emptive approach \n");
	printf("\n");
	SJFscheduling();
	printf("\n ---------------------------------------------------------------------------------------\n");
	printf("implement the priority scheduling \n");
	printf("\n");
	Priorityscheduling();
	printf("\n ---------------------------------------------------------------------------------------\n");
	printf("implement the Round Robin scheduling \n");
	printf("\n");
	Roundrobinscheduling();
	return 0;
}

