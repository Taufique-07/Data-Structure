#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head,*newnode,*temp,*current,*after,*prev,*tail;

void first()
{
    temp=head;
    current=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&current->data);
    temp->prev=current;
    current->next=head;
    head=current;
    current->prev=NULL;
}

void last()
{
    current=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&current->data);

    current->next=NULL;
    tail->next=current;
    current->prev=tail;
    tail=current;
}

void any(int n)
{
    int pos,count=0;
    int i=1;
    printf("Pos :");
    scanf("%d",&pos);

    if(pos<1 || pos>n+1)
    {
        printf("error.\n");
    }
    else
    {
        current=(struct node*)malloc(sizeof(struct node));

        if(pos==1)
        {
            first();
        }
        else if(pos==n)
        {
            last();
        }
        else
        {
            scanf("%d",&current->data);
            temp=head;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            current->next=temp->next;
            current->prev=temp;
            temp->next=current;
            temp=current->next;
            temp->prev=current;
        }
    }
}

void dfirst()
{
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}

void dlast()
{
    if(tail==NULL)
    {
        printf("Error.\n");
    }
    else
    {
       temp=tail;
       tail=tail->prev;
       tail->next=NULL;
       free(temp);
    }

}

void dany()
{
    int key;
    scanf("%d",&key);

    temp=head;
     while(temp!=NULL)
     {
         if(temp->data == key)
         {
            if(temp->prev!=NULL)
            {
                temp->prev->next=temp->next;
            }
            else
            {
                head=temp->next;
            }
            if(temp->next!=NULL)
            {
                temp->next->prev=temp->prev;
            }
            free(temp);
         }
         temp=temp->next;
     }
}

void create(int choice)
{
    head=NULL;
    tail=NULL;

    while(choice--)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL)
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
    temp=head;

    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void reverse()
{
    temp=tail;

    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
}


int main() {

   int choice;
   scanf("%d",&choice);
   create(choice);
   output();
 /*  reverse();
   first();
   output();
   reverse();
   last();
   output();
   reverse();
   any(choice);
     output();
   reverse();*/
   dfirst();
     output();
   reverse();
   dlast();
     output();
   reverse();
   dany();
    output();
   reverse();


    return 0;
}
