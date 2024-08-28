#include<stdio.h>

int main()
{
    int a[]={2,3,5,6,7};

    int key,count=0;
    scanf("%d",&key);

    for(int i=0; i<5; i++)
    {
        if(a[i]==key)
        {
            printf("It's in %d index.\n",i);
            count++;
            break;
        }
    }
    if(count==0)
        {
             printf("This number is not placed in this array.\n");
        }

}
