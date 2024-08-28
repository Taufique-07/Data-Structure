#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node *head,*tail,*temp;

void create(int choice)
{
    head=NULL;
    tail=NULL;
    struct node*newnode;

    while(choice--)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;

        if (head==NULL)
        {
            head=temp=newnode;
            tail=temp;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
            tail=temp;
        }
    }
}

void output()
{
    printf("Doubly linked list :\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        printf("%d\n",&temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reverse()
{
    printf("Reversed Doubly linked list :\n");
    temp=tail;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        printf("%d\n",&temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("How many Node you wanna create :");
    scanf("%d",&choice);

    create(choice);
    output();
    reverse();

    return 0;
}
