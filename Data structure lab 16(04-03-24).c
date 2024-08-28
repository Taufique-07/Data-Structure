#include<stdio.h>

#define MAX 10

int queue[MAX];
int front=-1;
int rare=-1;

void enqueue(int value)
{

    if(front==-1 && rare==-1)
    {
        front=rare=0;
        queue[rare]=value;
    }
     else if(front==MAX-1)
    {
        printf("This Queue is full.\n");
    }
    else
    {
        rare++;
        queue[rare]=value;
    }
}

void dequeue()
{
    if(front==-1 || front>rare)
    {
        printf("This Queue is Empty.\n");
    }
    else
    {
        front++;
    }
}

void output()
{
    if(front==-1 || front>rare)
    {
        printf("This Queue is Empty.\n");
    }
    else
        {

         for(int i=front; i<=rare ; i++)
          {
            printf("%d ",queue[i]);
          }
        }
    printf("\n");
}

int main()
{
    output();
    enqueue(8);
    enqueue(0);
    enqueue(1);
    enqueue(6);
    output();
    dequeue();
    dequeue();
    enqueue(5);
    output();

    return 0;
}
