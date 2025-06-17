#include<stdio.h>
#include<limits.h>
#define INF 99999
long int m[20][20];
int s[20][20];
int p[20];


void optimal_print(int i,int j)
{
    if(i==j)
    {
        printf("A%d",i);
    }
    else
    {
        printf("(");
        optimal_print(i,s[i][j]);
        optimal_print(s[i][j]+1,j);
        printf(")");

    }
}

void MatrixMultiplication(int n)
{
    long int q;
    for(int i=n;i>0;i--)
    {
        for(int j=i;j<=n;j++)
        {
            if(i==j)
            {
                m[i][j]=0;
            }
            else
            {
                for(int k=i;k<j;k++)
                {
                    q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    if(q<m[i][j])
                    {
                        m[i][j]=q;
                        s[i][j]=k;
                    }
                }
            }
        }
    }
}

int matrixChainOrder(int i,int j)
{
    if(i==j)
    {
        return 0;
    }
    int min=INT_MAX;
    int count;
    for(int k=i;k<j;k++)
    {
        count=matrixChainOrder(i,k)+matrixChainOrder(k+1,j)+p[i-1]*p[k]*p[j];
        if(count<min)
        {
            min=count;
        }
    }
    return min;
}

void main()
{
    int n;
    printf("Enter number of matrices:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            m[i][i]=0;
            m[i][j]=INF;
            s[i][j]=0;
        }
    }

    printf("Enter the dimension of the matrices:\n");
    for(int k=0;k<=n;k++)
    {
        printf("P%d:",k);
        scanf("%d",&p[k]);
    }

    MatrixMultiplication(n);

    printf("\n**********Cost matrix**********\n");

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            printf("m[%d][%d] = %ld\n",i,j,m[i][j]);
        }
    }
    
    printf("\n****************\n");
    optimal_print(1,n);
    printf("\n*********************\n");
    printf("\nMinimum number of multiplication : %d\n",matrixChainOrder(1,n));
}
