#include<stdio.h>
#define size 100


int min(int x,int y)
{
    return (x<y)?x:y;
}


void shortest_Path(int cost[size][size],int a[size][size],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=cost[i][j];
        }
    }

    for(int k=1;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));
            }
        }
    }
}

void display_matrix(int cost[size][size],int a[size][size],int n)
{
    // print adjacency matrix
    printf("---Adjacency matrix----\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cost[i][j]==99999)
            {
                printf("\tINF");
            }
            else
            {
                printf("\t%d",cost[i][j]);
            }
        }
        printf("\n");
    }

    printf("---------------------------------\n");

    // print shortest path matrix

    printf("---Shortest Path matrix----\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==99999)
            {
                printf("\tINF");
            }
            else
            {
                printf("\t%d",a[i][j]);
            }
        }
        printf("\n");
    }
}

void main()
{
    int cost[size][size],a[size][size];
    int n;

    printf("Enter the number of vertices:");
    scanf("%d",&n);

    printf("Enter the costs of the graph:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    shortest_Path(cost,a,n);
    display_matrix(cost,a,n);
}