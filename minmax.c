#include <stdio.h>

// structure to store min and max
struct Pair
{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int low, int high)
{
    struct Pair result, left, right;
    int mid;

    // Case 1: only one element
    if(low == high)
    {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // Case 2: two elements
    if(high == low + 1)
    {
        if(arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Divide
    mid = (low + high) / 2;

    // Conquer
    left = getMinMax(arr, low, mid);
    right = getMinMax(arr, mid + 1, high);

    // Combine
    if(left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    if(left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Pair ans = getMinMax(arr, 0, n-1);

    printf("Minimum element = %d\n", ans.min);
    printf("Maximum element = %d\n", ans.max);

    return 0;
}
