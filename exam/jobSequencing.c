#include<stdio.h>
#define MAX 100

typedef struct job{
    int id;
    int deadline;
    int profit;
}job;


// sort the jobs on the basis of their profits (bubble sort technique)
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
    printf("Sorted Jobs on the basis of their profit:\n");
    printf("%10s %10s %10s\n","Job Id","Deadline","Profit");
    for(int i=0;i<n;i++)
    {
        printf("%10d %10d %10d\n",jobs[i].id,jobs[i].deadline,jobs[i].profit);
    }
    printf("\n");
}

int findMin(int a,int b)
{
    int min=(a<b?a:b);
    return min;
}


void display_job_sequence(job jobs[],int timeSlot[],int dmax,int maxProfit)
{
    for(int i=1;i<=dmax;i++)
    {
        printf("%d",jobs[timeSlot[i]].id);
        if(i<dmax)
        {
            printf("--->");
        }
    }
    printf("\n");
    printf("Maximum profit is : %d\n",maxProfit);
}


void job_sequencing_deadline(job jobs[],int n)
{
    int timeslot[MAX]; //time slot for assigning the jobs
    int dmax=0; //for assigning maximum deadline
    int jobCount=0; //for assigning total number of jobs
    int maxProfit=0; // for counting maximum profit

    //sort the jobs according to their profit
    sort(jobs,n);


    //for finding maximum deadline
    for(int i=0;i<n;i++)
    {
        if(dmax<jobs[i].deadline)
        {
            dmax=jobs[i].deadline;
        }
    }

    //for assigning the time slot -1 for all the jobs initially
    for(int i=1;i<=dmax;i++)
    {
        timeslot[i]=(-1);
    }

    // calculating max profit by assigning the jobs by their deadline

    for(int i=0;i<n;i++)
    {
        int k=findMin(dmax,jobs[i].deadline);

        while(k>=1)
        {
            if(timeslot[k]==-1)
            {
                timeslot[k]=i;
                jobCount++;
                maxProfit+=jobs[timeslot[k]].profit;
                break;
            }
            k--;
        }
        if(dmax==jobCount)
        {
            break;
        }
    }

   display_job_sequence(jobs,timeslot,dmax,maxProfit);

}


void main()
{
    int n;
    printf("Enter the number of jobs:");
    scanf("%d",&n);

    job jobs[n];
    printf("Enter the jobs with id,deadline and profit:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&jobs[i].id,&jobs[i].deadline,&jobs[i].profit);
    }
    job_sequencing_deadline(jobs,n);
}