#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void deleteNode(int value)
{
    struct Node *temp = head, *prev = NULL;

    if (head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    if (head->data == value)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Deleted Successfully\n");
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element Not Found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Deleted Successfully\n");
}

void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    printf("Linked List : ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &value);
            insertEnd(value);
            break;

        case 2:
            printf("Enter Value to Delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }
}