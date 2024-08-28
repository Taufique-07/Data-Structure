#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head,*newnode,*temp,*current,*after,*prev;

void first()
{
    current=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&current->data);

    current->next=head;
    head=current;
}

void last()
{
    current=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&current->data);

    current->next=NULL;
    temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=current;
}

void any(int n)
{
    int pos;
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
            temp->next=current;
        }
    }
}

void dfirst()
{
    temp=head;
    head=head->next;
    free(temp);
}

void dlast()
{
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=NULL;
       // free(head);
    }
    else
    {
        prev->next=NULL;
    }
    free(temp);
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
             prev->next=temp->next;
             free(temp);
             break;
             }
             prev=temp;
             temp=temp->next;
     }

}

void create(int choice)
{
    head=NULL;

    while(choice--)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
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

int main() {

   int choice;
   scanf("%d",&choice);
   create(choice);
   output();
  /* first();
   output();
   last();
   output();
   any(choice);
   output();
   dfirst();
   output();
   dlast();
   output();*/
   dany();
   output();


    return 0;
}
