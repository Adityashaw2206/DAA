#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int matrix(int arr[],int i,int j)
{
    if(i == j)
    {
        return 0;
    }
    int k;
    int min = INT_MAX;
    int count;
    for(k=i;k<j;k++)
    {
        count = matrix(arr,i,k) + matrix(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(count <min)
            min = count;
    }
    return min;

}
int main()
{
    int i,n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the element of the array : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Minimum no of multiplication is : %d ",matrix(arr,1,n-1));
    return 0;
}