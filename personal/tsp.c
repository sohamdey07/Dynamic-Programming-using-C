#include <stdio.h>
#define INF 999

int a[10][10],visited[10],cost=0,n;

void get()
{
    printf("Enter number of cities:");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
        visited[i]=0;
    }

    printf("The cost list is:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

int least(int c) //here c means current city
{
    int nextCity=INF; //nextCity initialized to INF (a very large value) to represent no city found yet.
    int min=INF,kmin;

    for(int i=0;i<n;i++)
    {
        if((a[c][i]!=0)&&(visited[i]==0))
        {
            if(a[c][i]<min)
            {
                min=a[c][i]+a[i][0]; //cost of traveling (from current to next)+ (returning back from next to starting)
                kmin=a[c][i];//actial cost of traveling
                nextCity=i;
            }
        }
    }
    if(min!=INF)
    {
        cost+=kmin;//adding cost of traveling to the next city 
    }
    return nextCity; //return the next city to visit
}

void minCost(int city)
{
    int ncity;
    visited[city]=1;//mark the current city as visited
    printf("%d-->",city);
    ncity=least(city); //function is called to find the next city with the smallest cost

    if(ncity==INF)//if all the city is visited then,
    {
        ncity=0; //return to the starting city
        printf("%d",ncity);
        cost+=a[city][ncity]; //add the cost to return the starting city
        return; //end of recursion
    }
    minCost(ncity); // Recursively visit the next city
}


void put()
{
    printf("\n\nThe minimum cost is:%d\n\n",cost);
}

void main()
{
    get();
    printf("\nThe path is:\n");
    minCost(0);
    put();
}