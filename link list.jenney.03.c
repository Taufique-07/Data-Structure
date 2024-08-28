#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head,*newnode,*temp;
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
    temp->next=head;
     temp=head;
        while(temp->next!=head)
        {
            printf("%d ",temp->data);
            printf("%d \n",&temp->data);
            temp=temp->next;
        }
     return 0;

}
