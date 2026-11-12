#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before swapping:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i=0;i<n/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    printf("After swapping:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);  
    }
    return 0;
}