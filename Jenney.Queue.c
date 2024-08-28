#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int data;
    struct queue* next;
};

struct queue* front=NULL,*rare=NULL,*newnode,*temp;

void enqueue()
{
    int value;
    scanf("%d",&value);
    newnode=(struct queue*)malloc(sizeof(struct queue));
    newnode->data=value;
    newnode->next=NULL;

    if(front==NULL && rare==NULL)
    {
        front=rare=newnode;
    }
    else
    {
        rare->next=newnode;
        rare=newnode;
    }
}

void dequeue()
{
    temp=front;

    if(front==NULL && rare==NULL)
    {
        printf("This Queue is Empty.\n");
    }
    else
    {
        front=front->next;
    }
}

void output()
{
    temp=front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("How many element in Queue :");
    scanf("%d",&choice);

    for(int i=0; i<choice; i++)
    {
        printf("Enter data: ");
        enqueue();
    }
    output();
    dequeue();
    output();

    return 0;
}

