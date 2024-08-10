
#include <stdio.h>

int s[20], d[20];

void dij(int cost[10][10], int n, int src) {
    int i, u, min, ct;

    for (i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = cost[src][i];
    }

    s[src] = 1;
    ct = 1;

    while (ct < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            if (d[i] < min && s[i] == 0) {
                min = d[i];
                u = i;
            }
        }

        s[u] = 1;
        ct++;

        for (i = 1; i <= n; i++) {
            if (!s[i] && (d[u] + cost[u][i] < d[i])) {
                d[i] = d[u] + cost[u][i];
            }
        }
    }
}

void main() {
    int cost[10][10], n, i, j, src;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }

    printf("\nEnter the source node: ");
    scanf("%d", &src);

    dij(cost, n, src);

    printf("\nShortest path:\n");
    for (i = 1; i <= n; i++) {
        if (i != src) {
            printf("\n%d -> %d, cost = %d", src, i, d[i]);
        }
    }
}
