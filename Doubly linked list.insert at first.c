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

void output(struct node* head)
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
void reverse(struct node* tail)
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

void insertatfirst()
{
    temp=head;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    temp->prev=newnode;
    newnode->next=head;
    head=newnode;
    newnode->prev=NULL;
}

int main()
{
    int choice;
    printf("How many Node you wanna create :");
    scanf("%d",&choice);

    create(choice);
    output(head);
    reverse(tail);

    insertatfirst();

    output(head);
    reverse(tail);

    return 0;
}
