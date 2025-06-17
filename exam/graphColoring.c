#include<stdio.h>
#define size 50

int graph[size][size],color[size];


void displayColor(int n)
{
    printf("\nAssigned Color of the vertex:\n\n");
    for(int i=0;i<n;i++)
    {
        printf("Vertex %d ---> %d\n",i,color[i]);
    }
}

void nextColor(int k,int n)
{
    //Base case: if the vertices are processed.
    if(k==n)
    {
        displayColor(n);
        return;
    }
    
    //assigning the first current vertex as color 1
    color[k]=1;

    //to check if adjacent vertex have the same color or not
    for(int i=0;i<k;i++)
    {
        //if there are edge between 'i' and 'k' vertex and color of both is same then
        if(graph[i][k]!=0 && color[i]==color[k])
        {
            color[k]++;
            i=-1;
        }
    }

    //recurrsive call to the next vertex
    nextColor(k+1,n);
}


void main()
{
    int vertex,edge,k,l;
    printf("Enter the number of vertex:");
    scanf("%d",&vertex);

    printf("Enter the number of edges:");
    scanf("%d",&edge);

    //initialize the adjacency matrix by assigning zero to all vertex
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            graph[i][j]=0;
        }
    }

    printf("Enter the vertex value if there is any edge present:\n");
    for(int i=0;i<edge;i++)
    {
        scanf("%d %d",&k,&l);
        graph[k][l]=1;
        graph[l][k]=1;
    }
    printf("Adjacency matrix of the grapg is:\n");
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }

    nextColor(0,vertex);
}