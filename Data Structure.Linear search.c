#include<stdio.h>

int main()
{
    int num;
    printf("Enter How many element you wanna insert : ");
    scanf("%d",&num);
    int a[num];

    for(int i = 0; i < num; i++)
    {
        scanf("%d",&a[i]);
    }

    int key,count=0;
    printf("Enter which value you wanna search : ");
    scanf("%d",&key);

    for(int i=0; i<num; i++)
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
