#include <stdio.h>

#define MAX_SIZE 100

void findSubsets(int set[], int n, int index, int currentSum, int targetSum, int subset[], int subsetSize) {
    if (currentSum == targetSum) {
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    if (index >= n || currentSum > targetSum) return;

    subset[subsetSize] = set[index];
    findSubsets(set, n, index + 1, currentSum + set[index], targetSum, subset, subsetSize + 1);

    findSubsets(set, n, index + 1, currentSum, targetSum, subset, subsetSize);
}

int main() {
    int n, d;

    printf("Enter the n value: ");
    scanf("%d", &n);

    int set[MAX_SIZE];
    int subset[MAX_SIZE];

    printf("Enter the set in increasing order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the max subset value: ");
    scanf("%d", &d);

    printf("Subsets with the sum %d are:\n", d);
    findSubsets(set, n, 0, 0, d, subset, 0);

    return 0;
}
