#include<stdio.h>
//binary search
int search(int a[],int size, int key)
{
    int low=0,high=size-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int n[]={10,15,17,20,30,35,37,40,49,55,57};
    int key;
    int size= sizeof(n)/sizeof(n[0]);

    printf("Enter the element you wanna search : ");
    scanf("%d",&key);

    int result=search(n,size,key);

    if(result==-1)
    {
        printf("This element is not placed in this array.\n");
    }
    else
    {
        printf("This element is in index %d.\n",result);
    }
    return 0;
}
