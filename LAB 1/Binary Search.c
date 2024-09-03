#include <stdio.h>
int main()
{
        int n,i,k;
        printf ("Enter the number of elements\n");
        scanf ("%d", &n );
        int arr[n];
        printf("Enter the sorted elements\n");
        for ( i=0; i<n ; i++)
        {

            scanf("%d", &arr[i]);
        }
        printf("Enter the element to be searched\n");
        scanf ("%d", &k);
        int end=n;
        int start=0;
        int mid = ((end+start)/2);
        do {
            int mid = ((end+start)/2);
            if (arr[mid]>k){
                end = mid - 1;}
           else{
                start = mid + 1;}

        } while(arr[mid]!= k && start <= end);
        printf ("Element found at %d position", mid+1);

}
