#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student
{
    int m;
    float n;
    int o;
    char p[20];

};

struct node {
    struct student data;
    struct node* next;
};

struct node* create(struct student data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}


void insert(struct node** head, struct student data)
{
    struct node* newnode = create(data);
    newnode->next = *head;
   *head = newnode;
}



void output(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        printf("ID: %d\n", temp->data.id);
        printf("First Name: %c\n", temp->data.fname);
        printf("Name: %s\n", temp->data.name);
        printf("CGPA: %f\n\n", temp->data.cgpa);
        temp = temp->next;
    }
}

int main()
{

    struct node* head = NULL;

    struct student s1 = {100, 'V', "Ronaldo", 3.99};
    struct student s2 = {101, 'A', "Asif", 3.9};
    struct student s3 = {102, 'B', "Bob", 3.5};

    insert(&head, s1);
    insert(&head, s2);
    insert(&head, s3);


    printf("Linked List:\n");
    output(head);

    return 0;
}

