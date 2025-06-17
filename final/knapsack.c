#include<stdio.h>
#define MAX 20

void optimal(float x[],float maxprofit,int n)
{
    printf("The result vector is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
    }
    printf("\n");
    printf("The maximum profit is %f\n",maxprofit);
}

void itemsort(float weight[],float profit[],float ratio[],int n)
{
    float temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;
            }
        }
    }
}

void knapsack(float weight[],float profit[],int n,float capacity)
{
    float ratio[MAX];
    float maxprofit=0.0;
    float x[MAX];
    float u=capacity;
    int i;

    for(int i=0;i<n;i++)
    {
        ratio[i]=profit[i]/weight[i];
        x[i]=0.0;
    }

    itemsort(weight,profit,ratio,n);

    for(i=0;i<n;i++)
    {
        if(weight[i]<u)
        {
            x[i]=1.0;
            u=u-weight[i];
            maxprofit+=profit[i];
        }
        else
        {
            break;
        }
    }
    if(weight[i]>u && u!=0)
    {
        x[i]=u/weight[i];
        maxprofit+=profit[i]*x[i];
    }
    optimal(x,maxprofit,n);
}

void main()
{
    int n;
    float weight[MAX],profit[MAX];
    float capacity;
    printf("Enter the number of items:");
    scanf("%d",&n);

    printf("Enter the items with their weight and cost:\n");
    for(int i=0;i<n;i++)
    {
        printf("Item no. %d:",(i+1));
        scanf("%f %f",&weight[i],&profit[i]);
    }

    printf("Enter the capactity:");
    scanf("%f",&capacity);

    knapsack(weight,profit,n,capacity);
}