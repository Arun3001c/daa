#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int n, graph[MAX][MAX], path[MAX];

bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0) return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;
    return true;
}

void printSolution() {
    for (int i = 0; i < n; i++)
        printf("%d ", path[i] + 1);
    printf("%d\n", path[0] + 1);
}

void hamiltonianCycleUtil(int pos) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1)
            printSolution();
        return;
    }
    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            hamiltonianCycleUtil(pos + 1);
            path[pos] = -1;
        }
    }
}

void findHamiltonianCycles() {
    for (int i = 0; i < n; i++) path[i] = -1;
    path[0] = 0;
    hamiltonianCycleUtil(1);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Hamiltonian Cycles:\n");
    findHamiltonianCycles();
   
    return 0;
}
