#include<stdio.h>

#define MAX 100
// structure of job which has id,profit and specific deadline
typedef struct Job{
    int id;
    int deadline;
    int profit;
}Job;

// display the job sequence by their id
void display_job_sequence(Job jobs[],int dmax,int timeslot[],int maxprofit)
{
    for(int i=1;i<=dmax;i++)
    {
        printf("%d",jobs[timeslot[i]].id);
        if(i<dmax)
        {
            printf("--->");
        }
    }
    printf("\nMax Profit: %d\n",maxprofit);
}

// return the min value between two
int minValue(int a,int b)
{
    return a<b?a:b;
}

// sort the jobs based on their profit
void sort(Job jobs[],int n)
{
    Job temp;
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
    printf("\nSorted jobs on the basis of profit:\n");
    printf("%10s %10s %10s\n","Job Id","Deadline","Profit");
    for(int i=0;i<n;i++)
    {
        printf("%10d %10d %10d\n",jobs[i].id,jobs[i].deadline,jobs[i].profit);
    }
    printf("\n");
}


void job_sequence_with_deadline(Job jobs[],int n)
{
    // timeslots for assigning the jobs
    int timeslot[MAX];

    // for counting number of jobs
    int  jobCount=0;

    // for assigning maximum deadline
    int dmax=0;

    // for calculating maximum profit
    int maxprofit=0;

    // sort the jobs Decresing order of their profit
    sort(jobs,n);

    // find maximum deadline
    for(int i=0;i<n;i++)
    {
        if(dmax<jobs[i].deadline)
        {
            dmax=jobs[i].deadline;
        }
    }
    // initialize the timeslot with -1 [-1 denotes EMPTY]
    for(int i=1;i<=dmax;i++)
    {
        timeslot[i]=(-1);
    }

    // assigning all the jobs to the timeslot according their deadline
    for(int i=0;i<n;i++)
    {
        int k=minValue(dmax,jobs[i].deadline);
        while(k>=1)
        {
            if(timeslot[k]==(-1))
            {
                timeslot[k]=i;
                jobCount++;
                break;
            }
            k--;
        }

        if(jobCount==dmax)
        {
            break;
        }
    }
    for(int i=1;i<=dmax;i++)
    {
        maxprofit+=jobs[timeslot[i]].profit;
    }

    display_job_sequence(jobs,dmax,timeslot,maxprofit);
}

void main()
{
    int n;
    Job jobs[MAX];

    printf("Enter number of jobs:");
    scanf("%d",&n);
    
    printf("Enter job id,deadline,profit:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&jobs[i].id,&jobs[i].deadline,&jobs[i].profit);
    }
    job_sequence_with_deadline(jobs,n);
}