#include<stdio.h>
#include<stdlib.h>

struct f2
{
    int id;
    struct f2* next;
};

typedef struct f2 node;

int main()
{

    node *s1;
    s1=(node*)malloc(sizeof(node));
    node *s2;
    s2=(node*)malloc(sizeof(node));
    node *s3;
    s3=(node*)malloc(sizeof(node));
    node *head;
    head=s1;

    s1->id=10;
    s1->next=s2;

    s2->id=20;
    s2->next=s3;

    s3->id=30;
    s3->next=NULL;

    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->id);
        temp=temp->next;
    }
    printf("NULL \n");


   return 0;
}
