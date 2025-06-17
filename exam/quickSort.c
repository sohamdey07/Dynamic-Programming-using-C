#include<stdio.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;

    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[end],&arr[lb]);
    return end;
}

void quickSort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(arr,lb,ub);
        quickSort(arr,lb,loc-1);
        quickSort(arr,loc+1,ub);
    }
}

void display(int arr[],int lb,int ub)
{
    printf("Array elements are:\n");
    for(int i=lb;i<ub;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the number of elements in the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array elements are(before Sorting) :\n");
    display(arr,0,n);

    quickSort(arr,0,n);

    printf("Array elements are(After Sorting) :\n");
    display(arr,0,n);
}