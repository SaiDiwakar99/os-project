#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
float avg_wait_time(int wt[],int n)
{
	float x=0;
	int i,sum =0;
	for(i=0;i<n;i++)
	  sum = sum +wt[i];
x= sum* 1.0;
  x= x/n;
  return x;	  
}
float avg_turnaround_time(int tat[], int n)
{
	float x=0;
	int i,sum = 0;
	for(i=0;i<n;i++)
	 sum = sum +tat[i];
x= sum* 1.0;
x= x/n;
  return x;
}
void rearrange_process_queue(int pq[],int rt[],int pty[],int n,int running_processes)
{
	int i;
	if(pty[0]<pty[1])
	{
		int temp = pq[0];
		for(i=0;i<running_processes;i++)
		{
			pq[i]=pq[i+1];
		}
		pq[running_processes-1] = temp;
	}
	if(rt[pq[0]-1]==0)
	{
		int temp = pq[0];
		for(i=0;i<running_processes;i++)
		{
			pq[i]=pq[i+1];
		}
		pq[running_processes-1]=temp;
		running_processes=running_processes-1;
	}
	
}
void minptyinc(int pty[],int n)
{
	int i,min=pty[0];
	for(i=1;i<n;i++)
	{
		if(pty[i]==min)
		pty[i]++;
	}
	for(i=0;i<n;i++)
	{
		if(pty[i]==min)
		pty[i]++;
	}
}
int main()
{
 int count,i,j;
 int time_quantum,n;
 int time=0;
 printf("\n Enter Number of processes =");
 scanf("%d",&n);
 printf("Enter time quantum");
 scanf("%d",&time_quantum);
 if(n<=0||time_quantum <= 0)
 {
 	printf("invalid data");
 	return 0;
	 }
	 printf("the processes are set to %d\n The time Quantum is set to :%d\n",n,time_quantum);
	 int at[10],bt[10],rt[10],pq[10],pty[10],pty1[10],pflag[10],tat[10],wt[10];
	 for(j=0;j<n;j++)
	 {
	 	pq[j]=0;
	 	pflag[j]=0;
	 	
	 }
	 for(count=0;count<n;count++)
	 {
	 	printf("\nEnter Detail for processes =%d",count+1);
	 	printf("\n Enter arrival time =");
	 	scanf("%d",&at[count]);
	 	printf("\n Enter burst time =");
	 	scanf("%d",&bt[count]);
	 	printf("Enter priority =");
	 	scanf("%d",&pty[count]);
	 	rt[count]=bt[count];
	 	pty1[count]=pty[count];
	 	
	 if(at[count]<0||bt[count]<=0)
	 
	 {
	 	printf("Invalid data!!");
	 	return 0;
		 }	
	 }
int current=0;
int running_processes =0;
int x =0;
pq[0]=1;
running_processes=1;
pflag[0]=1;
int flag =0;

while (running_processes!=0)
{
 flag=0;
 x++;
 if(rt[pq[0]-1]>time_quantum)
 {
 	rt[pq[0]-1] =rt[pq[0]-1] - time_quantum;
 	current=time;
	 }	
	 else
	 {
	 	time = time + rt[pq[0]-1];
	 		 rt[pq[0]-1]=0;
	 		 flag =1;
	 		 current = time;
			 tat[pq[0]-1]=time - at[pq[0]-1];
	        wt[pq[0]-1]=tat[pq[0]-1]-bt[pq[0]-1];	
	 }
	for(i=0;i<n;i++)
	{
		if(at[i]<=time&& pflag[i]==0)
		{
			pq[running_processes]=i+1;
			running_processes = running_processes+1;
			pflag[i]=1;
		}
	}
if(x%2==0)
minptyinc(pty,n);

rearrange_process_queue( pq, rt, pty, n,running_processes);
if(flag ==1)
running_processes= running_processes-1;

}

printf("\n\nExecution Data:\n");
printf("|\tProcess\t|\tAT\t|\tBT\t|Priority|\tTAT\t|\tWT\t|\n");
for(i=0;i<n;i++)
{
	printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",i+1,at[i],bt[i],pty1[i],tat[i],wt[i]);
	
}
printf("\n\n Average waiting time = %f\n",avg_wait_time(wt,n));
printf(" Average turn around time = %f\n",avg_turnaround_time(tat,n));

return 0;
}

