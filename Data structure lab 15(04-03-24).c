#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
        {
        printf("Stack is full.\n");
        }
    else
        {
        top++;
        stack[top] = value;
        }
}

void pop()
{
    if (top == -1)
        {
        printf("Stack is empty.\n");
        }
    else
        {
        top--;
        }
}

void peek()
{
    if (top == -1)
        {
        printf("Stack is empty.\n");
        }
    else
        {
        printf("%d\n", stack[top]);
        }
}

void output()
{
    if (top == -1)
        {
        printf("Stack is empty.\n");
        }
    else
        {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
        }
}

int main()
{
    int choice, value;

    while (1)
        {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                output();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
