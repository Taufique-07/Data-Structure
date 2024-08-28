#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head,*newnode,*temp,*prev,*after;

void delete1st()
{
    temp=head;
    head=head->next;
    free(temp);
}

void deletelast()
{
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
}

void deleteatany(int n)
{
     int pos,i=1;
     printf("Enter Position : ");
     scanf("%d",&pos);


        if(pos>n)
        {
            printf("Invalid position.\n");
        }
        else
        {
            if(pos==1)
            {
                delete1st();
            }
            else if(pos==n)
            {
                deletelast();
            }
            else
            {
               temp=head;
               while(i<pos-1)
                {
                temp=temp->next;
                i++;
                }
                after=temp->next;
                temp->next=after->next;
                free(after);

            }
       }
}

void output()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    head=NULL;
    int choice;
    printf("Enter how many node you wanna create :");
    scanf("%d",&choice);
    int n=choice;

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
    output();
   // delete1st();
  //  printf("Linked list after deletion at 1st position:\n ");
  //  output();
    //deletelast();
  //  printf("Linked list after deletion at last :\n");
   // output();
    deleteatany(n);
    printf("Linked list after deletion at any position :\n");
    output();

    return 0;
}
