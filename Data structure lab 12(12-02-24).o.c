#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char m;
    float n;
    int o;
    char p[20];
    struct node* next;
};

void output(struct node *head)
{
    struct node *temp;
    temp= head;
    while(temp!=NULL)
    {
        printf("%c ",temp->m);
        printf("%.2f ",temp->n);
        printf("%d ",temp->o);
        printf("%s \n",temp->p);
        temp=temp->next;
    }
}

int main()
{
    struct node *x,*y,*z,*head,*temp;

    x=(struct node*)malloc(sizeof(struct node));
    y=(struct node*)malloc(sizeof(struct node));
    z=(struct node*)malloc(sizeof(struct node));

    head=x;
    x->m='A';
    x->n=3.5;
    x->o=10;
    strcpy(x->p, "BB");
    x->next=y;

    y->m='B';
    y->n=3.7;
    y->o=20;
    strcpy(y->p, "CC");
    y->next=z;

    z->m='C';
    z->n=3.9;
    z->o=30;
    strcpy(z->p, "DD");
    z->next=NULL;

    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->m='D';
    newnode->n=4.0;
    newnode->o=40;
    strcpy(newnode->p, "EE");
    newnode->next=x;
    head=newnode;

    struct node *new1;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->m='E';
    new1->n=4.0;
    new1->o=50;
    strcpy(new1->p, "FF");
    z->next=new1;
    new1->next=NULL;
    output(head);


    struct node * new2;
    new2=(struct node*)malloc(sizeof(struct node));
    new2->m='F';
    new2->n=4.0;
    new2->o=50;
    strcpy(new2->p, "GG");

    int pos,i=1;
    printf("Which position you wanna insert : ");
    scanf("%d",&pos);

    if(i<pos-1)
    {
          temp=head;
          while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            new2->next=temp->next;
            temp->next=new2;
    }
    else if(pos==1)
    {
        new2->next = head;
        head = new2;
    }

     output(head);

     temp=head;
     head=head->next;
     free(temp);

     printf("After deletion in 1st :\n");
     output(head);

     struct node* prev;
     prev=(struct node*)malloc(sizeof(struct node));
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
        printf("After deleting in last position :\n");
        output(head);
        int posi,j=1;
        printf("Enter the position you wanna delete : ");
        scanf("%d",&posi);
        struct node *after;
        after=(struct node*)malloc(sizeof(struct node));
           if(posi==1)
           {
               temp=head;
               head=head->next;
               free(temp);

           }
           else
           {
            temp=head;
            while(j<posi-1)
            {
                temp=temp->next;
                j++;
            }
            after=temp->next;
            temp->next=after->next;
            free(after);
           }
        printf("After deleting any position : \n");
        output(head);
        return 0;
}


