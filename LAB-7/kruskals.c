//mst using kruskals algorithm
#include<stdio.h>
struct Edge{
int u , v , weight;
};
int parent[100];
int find(int i)
{
    while(parent[i]!=i)
i=parent[i];
return i;
} 
void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU]=rootV;

}
void sortEdges(struct Edge edges[], int m)
{
    int i,j;
    struct Edge temp;
    for(i=0;i<m-1;i++)
    {
        for (j = 0; j < m - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
    }
}
    }
}
int main()
{
    int n, m;
    int i, count = 0;
    int totalWeight = 0;

    struct Edge edges[100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    sortEdges(edges, m);
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < m && count < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v))
        {
            printf("%d - %d = %d\n", u, v, edges[i].weight);

            totalWeight += edges[i].weight;
            unionSet(u, v);

            count++;
        }
    }

    printf("Total weight of MST = %d\n", totalWeight);

    return 0;
}