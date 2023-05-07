// FCFS (First Come First Serve) Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int at; //arrival time
    int bt; //burst time
    int st; //start time
    int et; //ent time
    int wt; //waiting time
    int tat; //turn-around time
    int rt; //response time
};

void main()
{
    struct process parr[100];
    int n,ct=0;
    float avgwt=0,avgtat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    for (int i=0;i<n;i++)
    {
        printf("Enter arrival time and burst time: ");
        scanf("%d %d",&parr[i].at,&parr[i].bt);

        parr[i].pid=i+1;
        parr[i].st=ct;
        ct+=parr[i].bt;
        parr[i].et=parr[i].st+parr[i].bt;
        parr[i].wt=parr[i].st-parr[i].at;
        avgwt+=parr[i].wt;
        parr[i].tat=parr[i].et-parr[i].at;
        avgtat+=parr[i].tat;
        parr[i].rt=parr[i].st-parr[i].at;    

        printf("\n");
    }
    for (int i=0;i<n;i++)
    {
        printf("%d  %d  %d  %d  %d  %d  %d  %d\n",parr[i].pid,parr[i].at,parr[i].bt,parr[i].st,parr[i].et,parr[i].wt,parr[i].tat,parr[i].rt);
    }

    avgwt/=n;
    avgtat/=n;
    printf("Average waiting time: %f",avgwt);
    printf("Average turn around time: %f",avgtat);
}