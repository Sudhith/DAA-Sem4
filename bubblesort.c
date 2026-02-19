#include<stdio.h>
void bubblesort(int a[],int n)
{
    int i,j,t;
    for(i = 0;i<n-1;i++)
    {
        for(j = 0;j < n-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }

        }
    }

    for(i = 0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
int main()
{
    int n;
    printf("Enter size of array : \n");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        printf("Enter %d element",i+1);
        scanf("%d",&arr[i]);

    }
    bubblesort(arr,n);
    return 0;
}