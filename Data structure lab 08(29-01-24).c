#include<stdio.h>

int main()
{
    int a,b,sum,mult;
    scanf("%d %d",&a,&b);

    int *p,*q;

    p=&a;
    q=&b;

    sum=*p+*q;
    mult=*p * *q;

    printf("Sum = %d\n",sum);
    printf("Mult = %d\n",mult);
}
