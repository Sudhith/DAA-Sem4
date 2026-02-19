#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int h, i, j, k;
    int b[100];   // merged array

    h = low;        // first half pointer
    i = low;        // merged array pointer
    j = mid + 1;    // second half pointer

    // merge both subarrays
    while(h <= mid && j <= high)
    {
        if(arr[h] <= arr[j])
        {
            b[i] = arr[h];
            h++;
        }
        else
        {
            b[i] = arr[j];
            j++;
        }
        i++;
    }

    // remaining elements of first half
    if(h > mid)
    {
        for(k = j; k <= high; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    else
    {
        // remaining elements of second half
        for(k = h; k <= mid; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }

    // copy back to original array
    for(k = low; k <= high; k++)
        arr[k] = b[k];
}

void mergeSort(int arr[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        // divide left
        mergeSort(arr, low, mid);

        // divide right
        mergeSort(arr, mid + 1, high);

        // merge
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n-1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
