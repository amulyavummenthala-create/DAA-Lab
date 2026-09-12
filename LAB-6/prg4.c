//Fractional Knapsack by greedy approach
#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int main()
{
    struct Item items[100], temp;
    int n, capacity;
    int i, j;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            capacity = capacity - items[i].weight;
            totalProfit = totalProfit + items[i].profit;
        }
        else
        {
            totalProfit = totalProfit + items[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}