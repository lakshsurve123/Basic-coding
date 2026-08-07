#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

int main() {
    struct Item item[20], temp;
    int n, i, j, capacity;
    float total = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Profit and Weight of item %d: ", i + 1);
        scanf("%d%d", &item[i].profit, &item[i].weight);

        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter Knapsack Capacity: ");
    scanf("%d", &capacity);

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(item[i].ratio < item[j].ratio) {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(capacity >= item[i].weight) {
            total += item[i].profit;
            capacity -= item[i].weight;
        }
        else {
            total += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f", total);

    return 0;
}