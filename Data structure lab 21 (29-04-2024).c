#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* root = NULL;

struct tree* create(int data)
{

    struct tree* newnode;
    newnode = (struct tree*)malloc(sizeof(struct tree));

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
};

void inorder(struct tree* root)
{
    if(root == NULL)
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

int main()
{
    root=create(5);
    root->left=create(10);
    root->right=create(2);
    root->left->left = create(3);
    root->left->right = create(2);
    inorder(root);

}


