#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head,*temp;

void create(int choice)
{
    head=NULL;
    struct node *newnode;

    while(choice--)
    {
      newnode=(struct node*)malloc(sizeof(struct node));
      printf("Enter data: ");
      scanf("%d",&newnode->data);
      newnode->prev = NULL;
      newnode->next = NULL;

      if(head==NULL)
      {
          head=temp=newnode;
      }
      else
      {
          temp->next=newnode;
          newnode->prev=temp;
          temp=newnode;
      }
    }

}

void output(struct node *head)
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
void reverse(struct node *head)
{
    printf("Reversed Linked List :\n");
    temp=head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        printf("%d \n",&temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void insert(int pos,int c)
{
    struct node *newnode;
    int i=1;
    int count=0;
    temp=head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    temp=head;
    if(pos<1 || pos>c+1)
    {
        printf("Invalid !\n");
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data you wanna insert: ");
        scanf("%d",&newnode->data);

        if(pos==1)
        {
            temp->prev=newnode;
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
            newnode->prev=NULL;
        }

        else if (pos>c)
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
    printf("Enter how many Node you wanna insert: ");
    scanf("%d",&choice);


    create(choice);
    output(head);
    reverse(head);
    printf("Enter where you wanna insert :");
    int pos;
    scanf("%d",&pos);
    insert(pos,choice);
    output(head);
    reverse(head);

}


