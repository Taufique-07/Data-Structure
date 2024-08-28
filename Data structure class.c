#include<stdio.h>
#include<stdlib.h>

struct node
{
    int a;
    struct node* b;//prev
    struct node* c;//next
};

struct node *temp,*head;

void output()
{
    temp=head;

    while(temp!=NULL)
    {
        printf("%d ",temp->a);
        temp=temp->c;
    }
    printf("\n");
}

int main()
{
    struct node* x,*y,*z,*newnode;
    x=(struct node*)malloc(sizeof(struct node));
    y=(struct node*)malloc(sizeof(struct node));
    z=(struct node*)malloc(sizeof(struct node));

    head=x;
    x->a=5;
    x->b=NULL;
    x->c=y;
    y->a=10;
    y->b=x;
    y->c=z;
    z->a=15;
    z->b=y;
    z->c=NULL;

    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->a=20;
    newnode->b=NULL;
    newnode->c=NULL;

    y->c=newnode;
    newnode->c=z;
    newnode->b=y;
    z->b=newnode;

    output();//

    temp = head;
    while (temp != NULL)
        {
        if (temp->a == 10)
        {
            if (temp->b != NULL)
            {
                temp->b->c = temp->c;
            }
            if (temp->c != NULL)
            {
                temp->c->b = temp->b;
            }
            free(temp);
            break;
        }
        temp = temp->c;
    }

    output();


}
