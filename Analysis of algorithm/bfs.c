#include <stdio.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if(rear == MAX - 1)
        return;

    if(front == -1)
        front = 0;

    queue[++rear] = value;
}

int dequeue()
{
    if(front == -1 || front > rear)
        return -1;

    return queue[front++];
}

void bfs(int start, int n)
{
    int i, vertex;

    enqueue(start);
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while(front <= rear)
    {
        vertex = dequeue();
        printf("%d ", vertex);

        for(i = 0; i < n; i++)
        {
            if(graph[vertex][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start, n);

    return 0;
}