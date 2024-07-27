#include <stdio.h>

#define MAX 50

int main() {
    float weight[MAX], profit[MAX], ratio[MAX];
    float TotalValue = 0.0, capacity;
    int n, i, j;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item[%d]: ", i);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++) ratio[i] = profit[i] / weight[i];
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                float temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
                temp = profit[i]; profit[i] = profit[j]; profit[j] = temp;
            }
        }
    }

    for (i = 0; i < n && weight[i] <= capacity; i++) {
        TotalValue += profit[i];
        capacity -= weight[i];
    }
    if (i < n) TotalValue += ratio[i] * capacity;

    printf("The maximum value is: %.2f\n", TotalValue);
    return 0;
}
