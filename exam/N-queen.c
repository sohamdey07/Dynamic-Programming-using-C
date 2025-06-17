#include<stdio.h>
#include<stdlib.h>

int x[20],count=1;

int place(int k,int i)
{
    for(int j=1;j<=k-1;j++)
    {
        if((x[j]==i))
        {
            return 0;
        }
        else if((abs(x[j]-i)==abs(j-k)))
        {
            return 0;
        }
    }
    return 1;
}


void display(int n)
{
    printf("Solution : %d\n\n",count);
    for(int i=1;i<=n;++i)
    {
        printf("\t%d",i);
    }
    for(int i=1;i<=n;++i)
    {
        printf("\n\n%d",i);
        for(int j=1;j<=n;++j)
        {
            if(x[i]==j)
            {
                printf("\tQ");
            }
            else
            {
                printf("\t-");
            }
        }
    }
    count++;
    printf("\n\n\n");
}

void NQueen(int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                display(n);
            }
            else
            {
                NQueen(k+1,n);
            }
        }
    }
}

void main()
{
    int n;
    printf("Enter the number of Queens:");
    scanf("%d",&n);

    NQueen(1,n);
}