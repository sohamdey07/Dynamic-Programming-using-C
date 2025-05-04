#include<stdio.h>
#define size 50

int graph[size][size],color[size]; // Adjacency matrix for the graph and color array for vertices

void display(int n)  // Function to display the color assigned to each vertex
{
    printf("Color of vertices are:\n");
    for(int i=0;i<n;i++)
    {
        printf("\nVertex[%d]--%d\n",i,color[i]); // Print the vertex and its assigned color
    }
}

// Recursive function to assign colors to vertices
void next_color(int k,int n)
{
    // Base case: If all vertices are processed, display the result
    if(k==n)
    {
        display(n); // Display the colors assigned to vertices
        return; // End recursion
    }

    // Start by assigning the first color to the current vertex
    color[k]=1;

   // Check all previously colored vertices to ensure no two adjacent vertices have the same color
   for (int i = 0; i < k; i++)
   {
       // If there is an edge between vertex `i` and vertex `k` and they have the same color
       if (graph[i][k] != 0 && color[k] == color[i])
       {
           color[k] = color[i] + 1; // Assign the next color to vertex `k`
       }
   }

   // Recursively color the next vertex
   next_color(k + 1, n);
}

void main()
{
    int vertex,edge,k,l;
    printf("Enter total number of Vertices:");
    scanf("%d",&vertex);

    printf("Enter total number of Edges:");
    scanf("%d",&edge);

    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            graph[i][j]=0;
        }
    }

    printf("Enter the vertices where value is 1:\n");
    for(int i=0;i<edge;i++)
    {
        scanf("%d %d",&k,&l);
        graph[k][l]=1;
        graph[l][k]=1;
    }
    next_color(0,vertex);
}