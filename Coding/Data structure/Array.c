#include <stdio.h>

void display(int arr[], int n) {
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int insert(int arr[], int n, int pos, int value) {
    int i;

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return n;
    }

    for (i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    return n + 1;
}

int deleteElement(int arr[], int n, int pos) {
    int i;

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return n;
    }

    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

int main() {
    int arr[100], n, i, pos, value, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\n1. Insert\n2. Delete\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter position (0-based): ");
        scanf("%d", &pos);

        printf("Enter value: ");
        scanf("%d", &value);

        n = insert(arr, n, pos, value);
    }
    else if (choice == 2) {
        printf("Enter position (0-based): ");
        scanf("%d", &pos);

        n = deleteElement(arr, n, pos);
    }
    else {
        printf("Invalid choice!\n");
        return 0;
    }

    display(arr, n);

    return 0;
}