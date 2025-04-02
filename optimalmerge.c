#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int optimalMerge(int files[], int n) {
    int totalCost = 0,mergeCost = 0;
    int i = 1;

    while (n > 1) {
        sort(files, n);

        mergeCost = files[0] + files[1];
        totalCost += mergeCost;

        files[0] = mergeCost;
        printf("Merge move%d: new root weight: %d\n",i,mergeCost);

        for (int i = 1; i < n - 1; i++) {
            files[i] = files[i + 1];
        }
        n--;
        i++;
    }
    printf("Optimal merge completed with root weight = %d\n",mergeCost);

    return totalCost;
}

int main() {
    int n;

    printf("Enter the number of files: ");
    scanf("%d", &n);

    int files[n];

    printf("Enter the sizes of the files: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }

    int minCost = optimalMerge(files, n);

    printf("Minimum cost for optimal merging: %d\n", minCost);

    return 0;
}
