#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insertFront(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if(front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        front->prev = newNode;
        front = newNode;
    }
}

void insertRear(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void deleteFront()
{
    if(front == NULL)
    {
        printf("Deque Empty\n");
        return;
    }

    struct Node *temp = front;

    printf("Deleted %d\n", front->data);

    front = front->next;

    if(front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    free(temp);
}

void deleteRear()
{
    if(rear == NULL)
    {
        printf("Deque Empty\n");
        return;
    }

    struct Node *temp = rear;

    printf("Deleted %d\n", rear->data);

    rear = rear->prev;

    if(rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    free(temp);
}

void display()
{
    struct Node *temp = front;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    insertFront(10);
    insertRear(20);
    insertFront(5);
    display();

    deleteRear();
    display();

    return 0;
}