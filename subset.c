#include <stdio.h>
#define MAX 100

int w[MAX], x[MAX];
int n, m;

void printSubset(int k) {
    printf("Subset found: { ");
    for (int i = 0; i <= k; i++) {
        if (x[i] == 1)
            printf("%d ", w[i]);
    }
    printf("}\n");
}

void SumOfSub(int s, int k, int r) {
    x[k] = 1;
    if (s + w[k] == m) {
        printSubset(k);
    } else if (s + w[k] + w[k + 1] <= m) {
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }

    x[k] = 0;
    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
        SumOfSub(s, k + 1, r - w[k]);
    }
}

int main() {
    int total = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in non-decreasing order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        total += w[i];
    }

    printf("Enter the required sum: ");
    scanf("%d", &m);

    if (total < m) {
        printf("No solution exists.\n");
        return 0;
    }

    printf("Subsets with sum %d:\n", m);
    SumOfSub(0, 0, total);

    return 0;
}
