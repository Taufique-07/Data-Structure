#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node * create(int choice)
{
    struct node* newnode,*head,*temp;
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
    return head;
}

struct node* insert(int pos)
{
    struct node* head;
    int count,i=0;
    if(pos<1 ||pos>count+1)
        {
            printf("Invalid position.\n");
        }
        else
        {
          struct node *current,*temp;
          current=(struct node*)malloc(sizeof(struct node));
          printf("Enter data you wanna input: ");
          scanf("%d",&current->data);

            if(pos==1)
            {
            current->next = head;
            head = current;
            }
            else
            {

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

void output(struct node* head)
{
    while (head != NULL)
        {
        printf("%d ", head->data);
        printf("%d\n", &head->data);
        head = head->next;
       }

}


int main()
{
    struct node *head,*newnode,*temp;
    head=NULL;
    printf("Enter how many data you wanna import: ");
    int choice,value,position;
    scanf("%d",&choice);

    int count=0,pos,i=1;


    system("cls");
    printf("Linked list before insertion.\n");
    output(head);

    printf("Enter Position : ");
    scanf("%d",&pos);

    insert(pos);

    output(head);
    return 0;
}
