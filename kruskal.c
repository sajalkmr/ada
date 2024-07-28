#include <stdio.h>
#include <stdlib.h>

#define INF 999
#define MAX 100

int parent[MAX];

int find(int i) {
    return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
}

void union_sets(int u, int v) {
    parent[find(u)] = find(v);
}

void kruskal(int n, int cost[MAX][MAX]) {
    int mincost = 0;
    int edges = 0;

    for (int i = 0; i < n; i++) parent[i] = i;

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
    while (edges < n - 1) {
        int min = INF, u = -1, v = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u != -1 && v != -1) {
            union_sets(u, v);
            printf("Edge %d: (%d, %d) cost: %d\n", edges++, u + 1, v + 1, min);
            mincost += min;
            cost[u][v] = cost[v][u] = INF;
        }
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int main() {
    int n, cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = INF;
        }
    }

    kruskal(n, cost);
    return 0;
}
