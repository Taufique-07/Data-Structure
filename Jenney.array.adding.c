#include <stdio.h>

int main()
{
    int a[50],size,num,pos;

    printf("Enter size :");
    scanf("%d",&size);


    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }
     printf("Enter position : ");
     scanf("%d",&pos);

    if(pos<0 || pos>size+1)
    {
        printf("Error !\n");
    }
    else
    {
        printf("Enter number : ");
        scanf("%d",&num);
        for(int i=size-1; i>=pos-1; i--)
        {
            a[i+1]=a[i];
        }
        a[pos-1]=num;
        size++;
        printf("The new array is :\n");

    for(int i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    }

    return 0;
}
