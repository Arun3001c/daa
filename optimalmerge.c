#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Min-heap structure
typedef struct {
    int arr[MAX];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(MinHeap *h, int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (h->arr[parent] > h->arr[index]) {
        swap(&h->arr[parent], &h->arr[index]);
        heapifyUp(h, parent);
    }
}

// Heapify down
void heapifyDown(MinHeap *h, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < h->size && h->arr[left] < h->arr[smallest]) {
        smallest = left;
    }
    if (right < h->size && h->arr[right] < h->arr[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&h->arr[smallest], &h->arr[index]);
        heapifyDown(h, smallest);
    }
}

// Insert into heap
void insertHeap(MinHeap *h, int value) {
    h->arr[h->size] = value;
    heapifyUp(h, h->size);
    h->size++;
}

// Extract minimum from heap
int extractMin(MinHeap *h) {
    int min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return min;
}

int optimalMerge(int files[], int n) {
    MinHeap heap;
    heap.size = 0;
    int totalCost = 0;
    int move = 1;

    // Insert all file sizes into the heap
    for (int i = 0; i < n; i++) {
        insertHeap(&heap, files[i]);
    }

    while (heap.size > 1) {
        int first = extractMin(&heap);
        int second = extractMin(&heap);
        int mergeCost = first + second;
        totalCost += mergeCost;

        printf("Merge move%d: new root weight: %d\n", move++, mergeCost);
        insertHeap(&heap, mergeCost);
    }

    printf("Optimal merge completed with root weight = %d\n", heap.arr[0]);
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
