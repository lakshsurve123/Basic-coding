#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];

void dfs(int vertex, int n)
{
    int i;

    visited[vertex] = 1;

    printf("%d ", vertex);

    for(i = 0; i < n; i++)
    {
        if(graph[vertex][i] == 1 && visited[i] == 0)
        {
            dfs(i, n);
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

    printf("\nDFS Traversal: ");

    dfs(start, n);

    return 0;
}