#include<stdio.h>

int main()
{
    int size,pos,num;
    printf("Enter a array size : ");
    scanf("%d",&size);
    int a[size];

    printf("Enter elements of array array  : ");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter position : ");
    scanf("%d",&pos);
    printf("Enter the number :");
    scanf("%d",&num);

    a[size]=a[pos-1];
    a[pos-1]=num;
    size++;
    printf("The new array is : \n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}


