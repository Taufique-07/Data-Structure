#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

struct node* root=NULL;

struct node* create()
{
    char data;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data ('.' for stop) :  \n");
    scanf(" %c",&data);

    if(data=='.')
    {
        free(newnode);
        return NULL;
    }

    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    printf("Enter left child of %c:\n", data);
    newnode->left = create();
   printf("Enter right child of %c:\n", data);
    newnode->right = create();

    return newnode;
};

void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {

        printf("%c ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {

        postorder(root->left);
        postorder(root->right);
        printf("%c ",root->data);

    }
}

int main()
{
    root = create();
    printf("In-order format : \n ");
    inorder(root);
    printf("\nPre-order format :\n");
    preorder(root);
    printf("\nPost-Order : \n");
    postorder(root);
}


