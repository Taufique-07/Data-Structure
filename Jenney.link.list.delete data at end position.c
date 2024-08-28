
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
int main()
{

    struct node *head,*newnode,*temp,*prev;
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

    printf("Linked list :\n");


    temp=head;
    while(temp!=0)
        {
            printf("%d ",temp->data);
            printf("%d \n",&temp->data);
            temp=temp->next;
        }
       temp=head;

        while(temp->next!=0)
        {

           prev=temp;
           temp=temp->next;
        }
        if(temp==head)
        {
            head=NULL;
            free(head);
        }
        else
        {
            prev->next=NULL;
        }
        free(temp);


        temp=head;
         printf("Updated Linked list :\n");
        while(temp!=0)
        {
            printf("%d ",temp->data);
            printf("%d \n",&temp->data);
            temp=temp->next;
        }


     return 0;

}

