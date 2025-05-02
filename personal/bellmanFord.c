#include<stdio.h>
#define size 100
#define INF 99999

void BellmanFord(int graph[size][size], int vertices, int edges, int source)
{
    int distance[size];

    for(int i=0; i<vertices; i++)
    {
        distance[i]=INF;
    }
    distance[source]=0;

    // Relax all edges |V|-1 times
    for(int j=1; j<=(vertices-1); j++)
    {
        for(int i=0; i<edges; i++)
        {
            int u = graph[i][0]; // Source vertex
            int v = graph[i][1]; // Destination vertex
            int weight = graph[i][2]; // Edge weight
            
            if(distance[u] != INF && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative weight cycles (optional)
    for(int i=0; i<edges; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];
        int weight = graph[i][2];
        
        if(distance[u] != INF && distance[u] + weight < distance[v])
        {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the shortest distances
    for(int i=0; i<vertices; i++)
    {
        printf("Distance from %d to %d is : %d\n", source, i, distance[i]);
    }
}

void main()
{
    int v,s,edge,graph[size][size];

    printf("Enter number of vertices:");
    scanf("%d",&v);
    printf("Enter number of edge:");
    scanf("%d",&edge);

    printf("Enter the source vertex:");
    scanf("%d",&s);

    printf("Enter the edges (source,destination,weight) in this form:\n");
    for(int i=0;i<edge;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    BellmanFord(graph,v,edge,s);
}