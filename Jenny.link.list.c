#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *newnode, *temp;
    head = NULL;
    int choice;

    printf("Enter how many data you wanna import: ");
    scanf("%d", &choice);

    while (choice--)
    {

        newnode = (struct node *)calloc(1, sizeof(struct node));
        printf("Enter data :");

        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        printf("%d \n", &temp->data);
        temp = temp->next;
    }

  /*  temp = head;
    while (temp != NULL)
    {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    */

    return 0;
}

