#include<stdio.h>
int gcd(int a , int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}
int main()
{
    int a,b;

    printf("enter first number \n");
    scanf("%d",&a);
    printf("Enter second number \n ");
    scanf("%d",&b);
    int c = gcd(a,b);
    printf("\n gcd is %d \n",c);

    
}