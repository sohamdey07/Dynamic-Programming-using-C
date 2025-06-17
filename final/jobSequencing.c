#include<stdio.h>
#define MAX 50

typedef struct job{
    int id;
    int profit;
    int deadline;
}job;

void sort(job jobs[],int n)
{
    job temp;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(jobs[j+1].profit>jobs[j].profit)
            {
                temp=jobs[j+1];
                jobs[j+1]=jobs[j];
                jobs[j]=temp;
            }
        }
    }
    printf("Sorted Jobs based on profit:\n");
    printf("%10s %10s %10s\n","Job Id","Profit","Deadline");
    for(int i=0;i<n;i++)
    {
        printf("%10d %10d %10d\n",jobs[i].id,jobs[i].profit,jobs[i].deadline);
    }
    printf("\n");
}

int findMin(int a,int b)
{
    int min=(a<b)?a:b;
    return min;
}

void display_job(job jobs[],int dmax,int timeslot[],int maxprofit)
{
    for(int i=1;i<=dmax;i++)
    {
        printf("%d",jobs[timeslot[i]].id);
        if(i<dmax)
        {
            printf("--->");
        }
    }
    printf("\n");
    printf("The maximum profit is %d\n",maxprofit);
}

void job_sequence(job jobs[],int n)
{
    int timeslot[MAX];
    int dmax=0;
    int maxprofit=0;
    int jobcount=0;

    for(int i=0;i<n;i++)
    {
        if(dmax<jobs[i].deadline)
        {
            dmax=jobs[i].deadline;
        }
    }
    for(int i=1;i<=dmax;i++)
    {
        timeslot[i]=-1;
    }
    sort(jobs,n);

    for(int i=0;i<n;i++)
    {
        int k=findMin(dmax,jobs[i].deadline);
        while(k>=1)
        {
            if(timeslot[k]==-1)
            {
                timeslot[k]=i;
                jobcount++;
                maxprofit+=jobs[timeslot[k]].profit;
                break;
            }
            k--;
        }
    }
    if(jobcount==dmax)
    {
        display_job(jobs,dmax,timeslot,maxprofit);
    }
}

void main()
{
    int n;
    job jobs[MAX];
    printf("Enter the number of jobs:");
    scanf("%d",&n);
    printf("Enter the jobs with id,profit and deadline:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&jobs[i].id,&jobs[i].profit,&jobs[i].deadline);
    }
    job_sequence(jobs,n);
}