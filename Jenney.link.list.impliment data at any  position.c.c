#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
int main()
{
    int count=0,pos,i=1;

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
     temp=head;
        while(temp!=0)
        {
            printf("%d ",temp->data);
            printf("%d \n",&temp->data);
            temp=temp->next;
            count++;
        }


        printf("Enter the position you wanna insert data : ");
        scanf("%d",&pos);

        struct node *current;
        current=(struct node*)malloc(sizeof(struct node));


        if(pos>count+1)
        {
            printf("Invalid position.\n");
        }
        else if(pos==1)
        {
            printf("Enter data you wanna input: ");
            scanf("%d",&current->data);

        current->next=head;
        head=current;
        }
        else
        {
            temp=head;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }

        printf("Enter data you wanna input: ");
        scanf("%d",&current->data);
        current->next=temp->next;
        temp->next=current;


        }
        temp=head;
        while(temp!=0)
          {
            printf("%d ",temp->data);
            printf("%d \n",&temp->data);
            temp=temp->next;
          }

     return 0;

}

