#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct node* create(int choice)
{
    struct node *head,*newnode, *temp;
    head=NULL;

    while(choice--)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &(newnode->data));
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }


void output1(struct node* head)
{
     struct node *temp;
     printf("Doubly linked list: \n");
     temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void output2(struct node*head)
{
    struct node *temp;
    printf("Doubly linked list in Reverse order: \n");
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

}

int main()
{

    int choice;
    printf("Enter how many data you want to import: ");
    scanf("%d", &choice);
    create(choice);
    output1(head);
    output2(head);

    return 0;
}
