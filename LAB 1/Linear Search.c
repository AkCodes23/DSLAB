#include <stdio.h>
int main()
{
        int n,i,k;
        int count = 0;
        printf ("Enter the number of elements\n");
        scanf ("%d", &n );
        int arr[n];
        printf("Enter the elements\n");
        for ( i=0; i<n ; i++)
        {scanf("%d", &arr[i]);}
        printf ("Enter the element to be found\n");
        scanf ("%d", &k);
        for ( i=0 ; i<n ; i++)
        {
            if (arr[i]==k)
            {
            count++;
            if (count == 1)
            printf("Element at position %d\n", i+1);
            else
            printf ("Element is not there");
            break;
            }
}
}
