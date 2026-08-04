#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    printf("%d Pushed\n", value);
}

void pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    struct Node *temp = top;

    printf("%d Popped\n", top->data);

    top = top->next;

    free(temp);
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack Empty\n");
        return;
    }

    printf("Top Element = %d\n", top->data);
}

void display()
{
    struct Node *temp = top;

    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int ch, value;

    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter Value: ");
                scanf("%d",&value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}