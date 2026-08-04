#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int value)
{
    struct Node *temp = head;

    while(temp != NULL && temp->data != value)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Element Not Found\n");
        return;
    }

    if(temp == head)
    {
        head = head->next;

        if(head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;

        if(temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted Successfully\n");
}

void display()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int ch, value;

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter Value: ");
                scanf("%d",&value);
                insertEnd(value);
                break;

            case 2:
                printf("Delete Value: ");
                scanf("%d",&value);
                deleteNode(value);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
}