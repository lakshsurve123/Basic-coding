#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1], profit[n + 1];

    printf("Enter weights:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &profit[i]);

    int capacity;

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int dp[n + 1][capacity + 1];

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i] <= w)
                dp[i][w] = max(profit[i] + dp[i - 1][w - weight[i]],
                               dp[i - 1][w]);

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\nMaximum Profit = %d", dp[n][capacity]);

    return 0;
}