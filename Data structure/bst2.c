#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

int countLeaf(struct Node *root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

int findMin(struct Node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root->data;
}

int findMax(struct Node *root)
{
    while(root->right != NULL)
        root = root->right;

    return root->data;
}

int height(struct Node *root)
{
    if(root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main()
{
    struct Node *root = NULL;

    int n, value;

    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter Value: ");
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("\nNumber of Leaf Nodes = %d\n", countLeaf(root));
    printf("Smallest Element = %d\n", findMin(root));
    printf("Largest Element = %d\n", findMax(root));
    printf("Height of Tree = %d\n", height(root));

    return 0;
}