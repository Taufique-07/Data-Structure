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
        printf("Enter data : ");
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

void insertatlast()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}

void insertatany(int choice)
{
    int pos;
    printf("Enter Which position you wanna insert New Node : ");
    scanf("%d",&pos);

    if(pos<0 || pos>choice+1)
    {
        printf("Invalid !\n");
    }
    else
    {
        struct node* newnode;
        newnode=(struct node*)malloc(sizeof(struct node));

        if(pos==1)
        {
            insertatfirst();
        }
        else if (pos>choice+1)
        {
           temp=head;
            while(temp->next!=NULL)
            {
                 temp=temp->next;
            }
              newnode->next=NULL;
              temp->next=newnode;
              newnode->prev=temp;
              newnode=temp;
        }

        else
        {
            struct node* newnode;
            int i=1,count=0;
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter data : ");
            scanf("%d",&newnode->data);
            temp=head;

            temp=head;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode->next;
            temp->prev=newnode;
        }


    }
}



int main()
{
    int choice;
    printf("How many Node you wanna create : ");
    scanf("%d",&choice);

    create(choice);
    output(head);
    reverse(tail);

    insertatfirst();

    output(head);
    reverse(tail);

    insertatlast();

    output(head);
    reverse(tail);

    insertatany(choice);

    output(head);
    reverse(tail);


    return 0;
}


