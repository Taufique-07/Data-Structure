#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *head,*newnode,*temp,*prev;

void any()
{
    int key;
    scanf("%d",&key);

    temp=head;
     while(temp!=NULL)
     {
         if(temp->data == key)
         {
             prev->next=temp->next;
             }
             prev=temp;
             temp=temp->next;
     }
}

int main()
{

    head=NULL;
    printf("Enter how many data you wanna import: ");
    int choice;
    scanf("%d",&choice);

    while(choice--)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");

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
    printf("My linked list :\n");
       temp=head;
        while(temp!=0)
        {
            printf("%d ",temp->data);
            printf("%d \n",&temp->data);
            temp=temp->next;
        }
        any();

        printf("Updated Linked list :\n");
         temp=head;
        while(temp!=0)
        {
            printf("%d ",temp->data);
            printf("%d \n",&temp->data);
            temp=temp->next;
        }

     return 0;

}
