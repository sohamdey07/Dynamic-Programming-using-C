#include<stdio.h>
#include<stdbool.h>
#define N 8

bool isSafe(int board[N][N],int row,int col)
{
    // horizontal check
    for(int i=0;i<col;i++)
    {
        if(board[row][i]==1)
        {
            return false;
        }
    }
    // upper left diagonal check
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    // lower left diagonal check
    for(int i=row,j=col;i<N && j<N;i++,j++)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    return true;
}


bool n_queens(int board[N][N],int col)
{
    if(col>=N) //base case: if all the queen is placed
    {
        return true;
    }
    for(int row=0;row<N;row++)
    {
        if(isSafe(board,row,col))
        {
            board[row][col]=1; //place the queen at board[row][col]

            if(n_queens(board,col+1))  // Recursively place the rest of the queens
            {
                return true;
            }

            board[row][col]=0; //backtracking
        }
    }
    return false;
}

void display(int board[N][N])
{
    printf("\nPossible position for %d Queens in a %dX%d board is:\n\n",N,N,N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j]==1)
            {
                printf("Q\t");
            }
            else
            {
                printf("-\t");
            }
        }
        printf("\n");
    }
}

void main()
{
    int board[N][N]={0}; //initialize board with 0

    if (n_queens(board, 0)) // Start placing queens from column 0
    {
        display(board); // Display the solution if it exists
    }
    else
    {
        printf("No solution exists for %d queens.\n", N);
    }
}