#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack* next;
};

struct stack* top=NULL,*newnode,*temp;

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

        if(temp==top)
        {
            top=NULL;
            free(top);
        }
        else
        {
           top=top->next;
        }
        free(temp);
}


void output()
{
    temp=top;

    if(top==NULL)
    {
        printf("Empty stack. \n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d \n",temp->data);
            temp=temp->next;
        }
    }
}

void peek()
{
    if (top==NULL)
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("Top element : %d\n",top->data);
    }
}

int main()
{
    int choice;
    printf("Enter stack size: ");
    scanf("%d",&choice);

    for(int i=0; i<choice; i++)
    {
        printf("Enter data: ");
        push();
    }
    output();
    peek();
    pop();
    output();
    peek();

    return 0;
}
