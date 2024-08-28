#include<stdio.h>

int main()
{
    int a[50],size,pos,num;
    printf("Enter a array size : ");
    scanf("%d",&size);

    printf("Enter elements of array array  : ");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter position : ");
    scanf("%d",&pos);

    a[pos-1]=a[size-1];
    size--;
    printf("The new array is : \n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}

