#include<stdio.h>
#include<stdlib.h>
#define size 10


void djkstra(int cost[size][size],int dist[size],int s,int n)
{
    int v=-1,count=0;
    int visited[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=cost[s][i];
        visited[i]=0;
    }
    visited[s]=1;
    dist[s]=0;

    while(count<=n)
    {
        int min=99999;
        v=-1;
        for(int i=0;i<n;i++)
        {
            if(dist[i]<min && visited[i]==0)
            {
                min=dist[i];
                v=i;
            }
        }
        if(v==-1) break;

        visited[v]=1;
        count++;

        for(int i=0;i<n;i++)
        {
            if(dist[i]>(dist[v]+cost[v][i]))
            {
                dist[i]=dist[v]+cost[v][i];
            }
        }
    }
}


void display_shortest_dist(int dist[size],int s,int n)
{
    printf("Shortest distance of all vertex from %d : ",s);
    for(int i=0;i<n;i++)
    {
        printf("\nVertex %d: %d\n", i, dist[i]);
    }
}




void main()
{
    int n,s;
    int cost[size][size];
    int dist[size];

    printf("Enter no of vertices:");
    scanf("%d",&n);
    printf("Enter the value in the cost matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i!=j)
            {
                cost[i][j]=99999;
            }
        }
    }
    printf("Cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }

    printf("Enter the source vertex:");
    scanf("%d",&s);

    djkstra(cost,dist,s,n);
    display_shortest_dist(dist,s,n);

}

// Enter number of vertices: 5
// Enter adjacency matrix:
// 0 10 0 30 100
// 10 0 50 0 0
// 0 50 0 20 10
// 30 0 20 0 60
// 100 0 10 60 0
// Enter source vertex: 0
// Enter target vertex: 4