#include <stdio.h>
#include <stdlib.h>

#define INF 99999
#define MAX 10

int main() {
    int n;
    int visited[MAX] = {0}; 
    int cost[MAX][MAX];      
    int mincost = 0;         
    int i, j, ne = 1;        

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    visited[1] = 1; 

    while (ne < n) {
        int min = INF;
        int a = -1, b = -1;

        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("\n Edge %d: (%d -> %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
            cost[a][b] = cost[b][a] = INF; 
        }
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
