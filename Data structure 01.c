#include<stdio.h>

int main()
{
    int size,num,pos;

    printf("Enter size :");
    scanf("%d",&size);

    int a[size];

    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }
     printf("Enter number and position.\n");
    scanf("%d %d",&num,&pos);

    if (pos<=0 || pos>size+1)
    {
        printf("Rafi\n");
    }
    else
    {

    for(int i= size-1; i>=pos-1; i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=num;
    size++;
    }

    printf("The new array is :\n");

    for(int i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
