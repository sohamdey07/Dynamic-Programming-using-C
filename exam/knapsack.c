#include<stdio.h>

void itemSort(float weight[],float profit[],float ratio[],int n)
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

void optimal(float x[],int n,float maxprofit)
{
    printf("The result vector is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
    }
    printf("\n");
    printf("The maximum profit = %f\n",maxprofit);
}

void kanpsack(float weight[],float profit[],float x[],int n,int capacity)
{
    int i;
    float maxprofit=0.0;
    int u=capacity;

    for(i=0;i<n;i++)
    {
        if(weight[i]<u)
        {
            x[i]=1.0;
            maxprofit+=profit[i];
            u=u-weight[i];
        }
        else
        {
            break;
        }
    }
    if((weight[i]>u) && u!=0)
    {
        x[i]=u/weight[i];
        maxprofit+=profit[i]*x[i];
    }
    optimal(x,n,maxprofit);
}

void main()
{
    int n;
    printf("Enter the number of items:");
    scanf("%d",&n);

    float weight[n],profit[n],ratio[n],x[n];
    int capacity;

    printf("Enter the jobs with their weights and profits :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%f %f",&weight[i],&profit[i]);
        ratio[i]=profit[i]/weight[i];
        x[i]=0.0;
    }
    printf("Enter the capacity:");
    scanf("%d",&capacity);
    
    itemSort(weight,profit,ratio,n);
    kanpsack(weight,profit,x,n,capacity);
}