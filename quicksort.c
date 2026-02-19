#include <stdio.h>

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];   // choosing first element as pivot
    int i = low + 1;
    int j = high;
    int temp;

    while(i <= j)
    {
        while(arr[i] <= pivot && i <= high)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // place pivot in correct position
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;   // pivot index
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        // sort left side
        quickSort(arr, low, p - 1);

        // sort right side
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
