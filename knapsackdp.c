#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, M, i, j;
    int w[10], p[10], v[10][10], x[10] = {0};

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the weights and profits of objects:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &p[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &M);

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= M; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (j < w[i]) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
        }
    }

    i = n;
    j = M;
    while (i != 0 && j != 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i] = 1;
            j -= w[i];
        }
        i--;
    }

    printf("The max profit obtained is %d\n", v[n][M]);
    printf("The objects considered are:\n");
    printf("objno\tweight\tprofit\n");
    for (i = 1; i <= n; i++) {
        if (x[i]) {
            printf("%d\t%d\t%d\n", i, w[i], p[i]);
        }
    }

    return 0;
}
