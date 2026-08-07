#include <stdio.h>

#define MAX 20

int parent[MAX];

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, i, j, min, cost[MAX][MAX];
    int a, b, u, v;
    int ne = 1, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Cost Matrix:\n");

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    while(ne < n) {

        min = 999;

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(uni(u, v)) {
            printf("%d Edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum Cost = %d", mincost);

    return 0;
}