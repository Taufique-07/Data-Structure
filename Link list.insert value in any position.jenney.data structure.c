
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert(struct node** head,int data)
{
    struct node* newnode = createnode(data);
     newnode->next = *head;
    *head = newnode;
}

void Position(struct node** head, int data,int position)
{

    if (position==1)
    {
        insert(head,data);
    }
    else
    {
        struct node* newnode = createnode(data);
        struct node* current = *head;

        for(int i = 1; i < position -1 && current != NULL; i++)
        {
           current = current->next;
        }
        if(current!=NULL)
        {
            newnode->next = current->next;
            current->next = newnode;
        }
    }
}
void output(struct node* head)
{
    int count=0;

    while(head!=NULL)
    {
        count++;
        printf("%d ",head->data);
        printf("%d \n",&head->data);
        head = head->next;
    }
    printf("The length of the Linked List is %d",count);
}

int main()
{
    struct node *head,*newnode,*temp;
    head=NULL;


    int choice,value,pos;
    printf("Enter how many element you wanna insert : ");
    scanf("%d",&choice);

    while(choice--)
    {
       newnode=(struct node*)malloc(sizeof(struct node));
       printf("Enter data : ");

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
    system("cls");

    printf("Linked list before insertion.\n");
    temp=head;
    while(temp!=NULL)
    {

        printf("%d ",temp->data);
        printf("%d \n",&temp->data);
        temp=temp->next;
    }



    printf("Enter a value to insert: ");
    scanf("%d", &value);
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    Position(&head, value, pos);

    printf("Linked List after insertion: \n");
    output(head);


    return 0;

}
