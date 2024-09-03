#include <stdio.h>
int main()
{
    int n,i,j;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for (i=0;i<n;i++)
    {
        scanf ("%d", &arr[i]);

    }
    for (i=0;i<n-1;i++)
    {
       int min = i;
       for ( j= i+1;j<n;j++)
       {
           if(arr[j]<arr[min])
           {
               min = j;
           }
       }
       int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    printf("The sorted array is \n");
    for (i=0 ; i< n ; i++)
    {
        printf("%d", arr[i]);
    }
}

