#include <stdio.h>
#define INF 9999
int main()
{
    int n;
    int graph[100][100];
    int selected[100] = {0};
    int i, j;
    int edges = 0;
    int totalWeight = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    selected[0] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n - 1)
    {
        int min = INF;
        int x = -1;
        int y = -1;
        for (i = 0; i < n; i++)
        {
            if (selected[i] == 1)
            {
                for (j = 0; j < n; j++)
                {
                    if (selected[j] == 0 &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (x == -1 || y == -1)
        {
            printf("MST cannot be formed.\n");
            return 0;
        }
        printf("%d - %d = %d\n", x, y, graph[x][y]);
        totalWeight += graph[x][y];

        selected[y] = 1;
        edges++;
    }
    printf("Total weight of MST = %d\n", totalWeight);
    return 0;
}