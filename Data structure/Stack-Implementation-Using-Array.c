#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    stack[++top] = value;
    printf("%d pushed into stack.\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }

    printf("%d popped from stack.\n", stack[top--]);
}

void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element = %d\n", stack[top]);
}

void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack: ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
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
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}