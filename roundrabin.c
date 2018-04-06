#include<stdio.h> 
#include<conio.h>
int main() 
{ 
 
  int con,j,n,time,remain,flag=0,tq; 
  int wt=0,tat=0,at[10],bt[10],rt[10]; 
  printf("Enter The Total No Of Process:\t "); 
  scanf("%d",&n); 
  remain=n; 

  for(con=0;con<n;con++) 

  { 

    printf("Enter The Arrival Time and  The Burst Time for Process Number %d :",con+1); 
    scanf("%d",&at[con]); 
    scanf("%d",&bt[con]); 
    rt[con]=bt[con]; 

  } 

  printf("Enter Time Quantum:\t"); 
  scanf("%d",&tq); 
  printf("\n\nProcess\t  | Turnaround Time  |  Waiting Time\n\n"); 

  for(time=0,con=0;remain!=0;) 

  { 

    if(rt[con]<=tq && rt[con]>0) 

    { 

      time+=rt[con]; 
      rt[con]=0; 
      flag=1; 

    } 

    else if(rt[con]>0) 

    { 

      rt[con]-=tq; 
      time+=tq; 

    } 

    if(rt[con]==0 && flag==1) 

    { 

      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",con+1,time-at[con],time-at[con]-bt[con]); 
      wt+=time-at[con]-bt[con]; 
      tat+=time-at[con]; 
      flag=0; 

    } 

    if(con==n-1) 
      con=0; 
    else if(at[con+1]<=time) 
      con++; 
    else 
      con=0; 

  } 

  printf("\nAverage Waiting Time= %f\n",wt*1.0/n); 
  printf("Avg Turnaround Time = %f",tat*1.0/n); 
    return 0; 

}
