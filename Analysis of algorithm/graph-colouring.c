#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int color[MAX];
int n, m;

int isSafe(int vertex, int c)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(graph[vertex][i] && color[i] == c)
            return 0;
    }

    return 1;
}

void graphColoring(int vertex)
{
    int c;

    if(vertex == n)
    {
        printf("\nColor Assignment:\n");

        for(int i = 0; i < n; i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);

        return;
    }

    for(c = 1; c <= m; c++)
    {
        if(isSafe(vertex, c))
        {
            color[vertex] = c;

            graphColoring(vertex + 1);

            color[vertex] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(0);

    return 0;
}