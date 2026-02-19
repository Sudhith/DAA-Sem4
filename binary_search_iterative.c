#include <stdio.h>

int binarySearchIterative(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return 1;   // found

        else if(key < arr[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return 0; // not found
}

int main()
{
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);
    int r = binarySearchIterative(arr, n, key);
    if(r==1)
        printf("Found");
    else
        printf("Not Found");

    return 0;
}
