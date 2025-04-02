#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int colors[MAX];
int n;

bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int m, int v) {
    if (v == n) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            colors[v] = c;

            if (graphColoringUtil(m, v + 1)) {
                return true;
            }

            colors[v] = 0;
        }
    }
    return false;
}

void graphColoring(int m) {
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }

    if (!graphColoringUtil(m, 0)) {
        printf("Solution does not exist\n");
        return;
    }

    printf("Solution Exists: Assigned colors are:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d -> Color %d\n", i, colors[i]);
    }
}

int main() {
    int m;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(m);

    return 0;
}
