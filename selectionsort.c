#include<stdio.h>
void selectionSort(int a[],int n)
{
    int i,j,t,min;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[min])
            {
                min = i;
            }
            t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
    }
    printf("sorted array \n");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
int main()
{
    int n;
    printf("Enter size of array \n");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n;i++)
    {
        printf("Enter %d element ",i+1);
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
}
