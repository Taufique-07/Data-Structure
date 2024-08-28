#include<stdio.h>

int main()
{
    int a[]={2,3,4,66,4,20};
    int key,count=0;
    int size=sizeof(a)/sizeof(a[0]);
    printf("Enter which value you wanna search :");
    scanf("%d",&key);

     for(int i=0; i<size; i++)
    {
        if(a[i]==key)
        {
            printf("It's in %d index.\n",i);
            count++;

        }
    }
    if(count==0)
        {
             printf("This number is not placed in this array.\n");
        }
        printf("%d occur %d times.\n",key,count);


    return 0;
}
