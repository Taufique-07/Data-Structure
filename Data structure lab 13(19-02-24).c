#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{

 int data;
 struct node *next;

};
 typedef struct node Node;
 Node *head=NULL;

 void print()
 {
     printf("Printing the linked list:\n");
     Node *p=head;
     while(p!=NULL)
     {
         printf("%d ",p->data);
         p=p->next;
     }
     printf("\n");
 }

 void insertB()
 {
     printf("Inserting Node before Head:\n");
     int data;
     Node *lk;
     lk=(Node *)malloc(sizeof(Node));
     printf("Enter the data item:");
     scanf("%d",&data);
     lk->data=data;
     lk->next=head;
     head=lk;
 }

void insert_last_position()
{
    Node *ptr=head;
    if(ptr==NULL)
    {
       insertB();
       return;
    }
   printf("Inserting Node At last position:\n");
    Node *new_node;
    new_node=(Node *)malloc(sizeof(Node));
    int data;
    printf("Enter the data item: ");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=NULL;


    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;

}

 void insert_at_any_position()
  {
      int key;
      printf("Where you want to insert (after which item):");
      scanf("%d",&key);
    Node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==key)
        {
            Node *new_node;
            new_node=(Node *)malloc(sizeof(Node));
            int data;
            printf("Enter the data item: ");
            scanf("%d",&data);
            new_node->data=data;
            new_node->next=ptr->next;
            ptr->next=new_node;

            return;
        }
        else
            ptr=ptr->next;

    }

    insert_last_position();

}

void delete_head()
{
    printf("Deleting Head\n");
    head=head->next;
}
void delete_last_node()
{
    printf("Deleting Last Node\n");
    Node *ptr=head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=NULL;
}
void delete_any_position()
{
    int key;
    printf("Which node you want to delete (Enter the value): ");
    scanf("%d",&key);
    Node *ptr=head;
    Node *previous;
    if(ptr==NULL)
    {
        printf("Empty Linked list. So, delete operation is not possible.\n");
        return;
    }
    if(ptr!=NULL & ptr->data==key)
    {
        head=ptr->next;
        return;
    }
    while(ptr!=NULL & ptr->data!=key)
    {
        previous=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("The item is not present in the linked list that you want to delete.\n");
        return;
    }
    previous->next=ptr->next;
}

int main()
 {

      insert_last_position();
       print();
       insert_last_position();
       print();
       insert_last_position();
       print();
       delete_any_position();
       print();
       delete_last_node();
        print();

     return 0;
 }
