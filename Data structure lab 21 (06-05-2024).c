#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int data)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;

}

void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
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
        printf("%d ",root->data);
    }
}

struct node* insert(struct node* root,int a)
{
    if(root==NULL)
    {
        return create(a);
    }

    if(a>root->data)
    {
       root->right = insert(root->right,a);
       return root;
    }

    else if(a<root->data)
    {
        root->left = insert(root->left,a);
    }
    return root;
}

int search(struct node* root, int key)
{
    if (root == NULL)
        return -1;

    int count = 0;

    while (root != NULL)
        {
        if (key == root->data)
            return count;
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
        count++;
    }

    return -1;
}


int main()
{

    struct node * root=NULL;

    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,10);
    root=insert(root,60);
    root=insert(root,55);
    printf("Preorder:\n");
    preorder(root);

    printf("\n");
    printf("Inorder:\n");
    inorder(root);

    printf("\n");
    printf("Postorder:\n");
    postorder(root);

    printf("\n");
    printf("%d ",search(root,10));
    return 0;
}

