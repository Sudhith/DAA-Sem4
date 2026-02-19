#include<stdio.h>
int gcd(int a , int b)
{
    int r =0;
    while(b!=0)
    {
        r = a %b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int a,b;

    printf("enter first number /n");
    scanf("%d",&a);
    printf("Enter second number");
    scanf("%d",&b);
    int c = gcd(a,b);
    printf("/n gcd is %d /n",c);

    
}