
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

void any()
{
    int key;
  printf("After which data you wanna insert :");
  scanf("%d",&key);
   temp=head;
   while(temp!=NULL)
   {
       if(temp->data==key)
       {
           current=(struct node*)malloc(sizeof(struct node));
           printf("Enter data : ");
           scanf("%d",&current->data);
           current->next=temp->next;
           current->prev=temp;

           if(temp->next!=NULL)
           {
               temp->next->prev=current;
           }
           temp->next=current;
          if(temp==tail)
          {
              tail=current;
          }
           break;

       }
       temp=temp->next;
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


int main()
{
    int choice;
    printf("How many Node you wanna create :");
    scanf("%d",&choice);

    create(choice);
    output();
    reverse();
    any();
    output();
    reverse();
    any();
    output();
    reverse();



    return 0;
}

