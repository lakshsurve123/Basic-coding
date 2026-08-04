#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void reverse()
{
    if(head == NULL)
        return;

    struct Node *stack[100];
    int top = -1;

    struct Node *temp = head;

    while(temp != NULL)
    {
        stack[++top] = temp;
        temp = temp->next;
    }

    head = stack[top--];
    temp = head;

    while(top >= 0)
    {
        temp->next = stack[top--];
        temp = temp->next;
    }

    temp->next = NULL;
}

void display()
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Original List:\n");
    display();

    reverse();

    printf("Reversed List:\n");
    display();

    return 0;
}