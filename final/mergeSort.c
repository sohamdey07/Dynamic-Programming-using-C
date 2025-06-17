#include<stdio.h>

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void merge(int arr[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int B[ub+1];

    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            B[k]=arr[i];
            i++;
        }
        else
        {
            B[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            B[k]=arr[j];
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            B[k]=arr[i];
            i++;
        }
    }
    k++;
    for(int k=lb;k<=ub;k++)
    {
        arr[k]=B[k];
    }
}

void mergeSort(int arr[],int lb,int ub)
{
    int mid=(lb+ub)/2;
    if(lb<ub)
    {
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the element of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Array before sorting:\n");
    display(arr,n);

    printf("Array after sorting:\n");
    mergeSort(arr,0,n);
    display(arr,n);


}