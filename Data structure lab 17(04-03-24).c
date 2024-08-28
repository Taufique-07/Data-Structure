#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack* next;
};

struct stack *top=NULL,*newnode,*temp;

void push()
{
    int value;
    scanf("%d",&value);
    newnode=(struct stack*)malloc(sizeof(struct stack));
    newnode->data=value;
    newnode->next=top;
    top=newnode;
}

void pop()
{

    if(top==NULL)
    {
        printf("Empty!\n");
    }
    else
    {
    temp=top;
    top=top->next;
    free(temp);
    }
}

void output()
{
    temp=top;

    if(top==NULL)
    {
        printf("Empty Stack.\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("Enter how many element you wanna push:");
    scanf("%d",&choice);

    for(int i=0; i<choice;i++)
    {
        printf("Enter data : ");
        push();
    }
     output();
     pop();
     output();
     pop();
     output();

     return 0;
}
