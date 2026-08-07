#include <stdio.h>

#define INF 9999
#define MAX 10

int main() {
    int n, i, j, u, v, count;
    int cost[MAX][MAX], dist[MAX], visited[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Cost Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex (0-%d): ", n-1);
    scanf("%d", &u);

    for(i = 0; i < n; i++) {
        dist[i] = cost[u][i];
        visited[i] = 0;
    }

    dist[u] = 0;
    visited[u] = 1;

    for(count = 1; count < n; count++) {
        int min = INF;

        for(i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                v = i;
            }
        }

        visited[v] = 1;

        for(i = 0; i < n; i++) {
            if(!visited[i] && dist[v] + cost[v][i] < dist[i]) {
                dist[i] = dist[v] + cost[v][i];
            }
        }
    }

    printf("\nShortest Distances:\n");
    for(i = 0; i < n; i++)
        printf("%d -> %d = %d\n", u, i, dist[i]);

    return 0;
}