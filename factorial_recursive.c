#include<stdio.h>

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n * fact(n-1);
    }
}

int main()
{
    int n;
    printf("Enter The number : \n");
    scanf("%d",&n);

    int r = fact(n);

    printf("\nFactorial of %d is : %d", n, r);
}