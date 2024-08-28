#include<stdio.h>

int main()
{
    int a[]={1,2,3,4,5,6,7,8};//by default indexing completed.

    int size=sizeof(a)/sizeof(a[0]);//equation for calculate the size of array

    printf("%d\n",size);


    printf("Array:\n");
   for(int i=1; i<=size; i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
