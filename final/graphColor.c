#include<stdio.h>
#define size 50

int graph[size][size],color[size];

void displayColor(int n)
{
    printf("The assigned colors are:\n");
    for(int i=0;i<n;i++)
    {
        printf("Vertex %d --> %d\n",i,color[i]);
    }
    printf("\n");
}

void nextColor(int k,int n)
{
    if(k==n)
    {
        displayColor(n);
        return;
    }
    color[k]=1;
    for(int i=0;i<k;i++)
    {
        if(graph[i][k]!=0 && color[i]==color[k])
        {
            color[k]++;
            i=-1;
        }
    }
    nextColor(k+1,n);
}

void main()
{
    int n,edge,l,k;

    printf("Enter the number of vertex:");
    scanf("%d",&n);
    printf("Enter the number of edge:");
    scanf("%d",&edge);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }

    printf("Enter the vertices if there is an edge between them:\n");
    for(int i=0;i<edge;i++)
    {
        scanf("%d %d",&l,&k);
        graph[l][k]=1;
        graph[k][l]=1;
    }
    nextColor(0,n);
}