//NP Priority (Non Preemptive Priority based) Scheduling Algorithm

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
    int done;
    int pr; // priority
};

void main()
{
    struct process parr[10];
    int n,min,ct=0,minat=9999999;
    float avgwt=0,avgtat=0;
    
    printf("Enter number of processes: ");
    scanf("%d",&n);

    //Getting input from the user
    for (int i=0;i<n;i++)
    {
        printf("Enter arrival time, burst time and priority: ");
        scanf("%d %d %d",&parr[i].at,&parr[i].bt,&parr[i].pr);
        printf("\n");
        parr[i].pid=i+1;
        if (parr[i].at < minat)
        {
            minat=parr[i].at;
        }
        parr[i].done=0;
    }
    ct=minat;

    while(1)
    {
        min=-1;
        for (int i=0;i<n;i++)
        {
            if ((!parr[i].done) && (parr[i].at<=ct) && (min==-1 || parr[i].pr<parr[min].pr))
            {
                min=i;
            }
        }

        if (min==-1)
        {
            break;
        }

        if (parr[min].done==0)
        {
            if (ct < parr[min].at)
            {
                   ct = parr[min].at;
            }
            parr[min].st=ct;
            ct+=parr[min].bt;
            parr[min].et=parr[min].st+parr[min].bt;
            parr[min].wt=parr[min].st-parr[min].at;
            avgwt+=parr[min].wt;
            parr[min].tat=parr[min].et-parr[min].at;
            avgtat+=parr[min].tat;
            parr[min].rt=parr[min].st-parr[min].at;
            parr[min].done=1;
        }
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