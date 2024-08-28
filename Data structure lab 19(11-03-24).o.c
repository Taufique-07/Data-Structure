#include<stdio.h>
#include<stdlib.h>

int search(int ar[],int num)
{
    int first=0,last=num-1;
    int digit = 5;
    for(int i=0;i<num;i++)
    {
        int mid = (first+last)/2;
        if (ar[mid]==digit)
        {
            return mid;

        }
        if(ar[mid]<digit)
        {
            first = mid+1;
        }
        else if (ar[mid]>digit)
        {
            last = mid-1;
        }
    }
    return -1;
}
int main()
{
    int ar[]={2,3,8,9,10};
    int size = (sizeof (ar))/sizeof(ar[0]);

    int result = search(ar,size);
    if (result==-1)
    {
        printf("Not found");
    }
    else
    {
        printf("the digit is find the position of %d",result);
    }
}
