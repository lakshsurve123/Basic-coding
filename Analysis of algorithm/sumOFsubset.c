#include <stdio.h>

int w[20], x[20], n, target;

void subset(int sum, int k)
{
    int i;

    if(sum == target)
    {
        printf("{ ");

        for(i = 0; i < k; i++)
        {
            if(x[i])
                printf("%d ", w[i]);
        }

        printf("}\n");

        return;
    }

    if(k == n || sum > target)
        return;

    x[k] = 1;
    subset(sum + w[k], k + 1);

    x[k] = 0;
    subset(sum, k + 1);
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nPossible subsets:\n");

    subset(0, 0);

    return 0;
}