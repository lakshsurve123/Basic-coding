#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;
int minCost = 99999;

void tsp(int city, int count, int cost)
{
    int i;

    if(count == n && graph[city][0] != 0)
    {
        cost += graph[city][0];

        if(cost < minCost)
            minCost = cost;

        return;
    }

    for(i = 0; i < n; i++)
    {
        if(!visited[i] && graph[city][i] != 0)
        {
            visited[i] = 1;

            tsp(i, count + 1, cost + graph[city][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    visited[0] = 1;

    tsp(0, 1, 0);

    printf("\nMinimum Cost = %d", minCost);

    return 0;
}