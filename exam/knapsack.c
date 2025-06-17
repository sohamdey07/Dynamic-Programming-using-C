#include<stdio.h>

float total_profit,x[50];

void display(int n)
{
    printf("The Solution vector will be:\n");
    for(int i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
    }
    printf("\n");
    printf("Maximum profit: %f\n",total_profit);
}

// sort the item on the basis of p/w ratio
void sort_decending(float weight[],float profit[],float ratio[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;

                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;

                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
            }
        }
    }
}

void greedy_knapsack(int n,float weight[],float profit[],float capacity)
{
    int i;
    int u=capacity;
    // initialize the solution vector
    float ratio[20];

    
    for(i=0;i<n;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }

    //initialise the solution vector by 0.0
    for(i=0;i<n;i++)
    {
        x[i]=0.0;
    }

    //sort the items
    sort_decending(weight,profit,ratio,n);


    for(i=0;i<n;i++)
    {
        //if item's weight > remaining capacity then break from the loop
        if(weight[i]>u)
        {
            break;
        }
        else
        {
            //if under capacity value the take as a whole
            x[i]=1.0;
            total_profit+=profit[i];
            u=u-weight[i];
        }
    }
    //take the small portion /fractional of the item
    if(i<n)
    {
        x[i]=u/weight[i];
        total_profit+=(profit[i]*x[i]); //fractional profit
    }
    display(n);//display the vector and max profit
}

void main()
{
    int n,capacity;
    printf("Enter the number of jobs:");
    scanf("%d",&n);

    float weight[20],profit[20];
    printf("Enter the items with their weight and profit:\n");
    for(int i=0;i<n;i++)
    {
        printf("item no %d : ",i+1);
        scanf("%f %f",&weight[i],&profit[i]);
    }
    printf("Enter the capacity:");
    scanf("%d",&capacity);
    greedy_knapsack(n,weight,profit,capacity);
}