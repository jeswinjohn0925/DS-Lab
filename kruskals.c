#include <stdio.h>

int parent[10];

// Function to find the parent of a node (with path compression)
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Function to perform union of two sets
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, n, a, b, u, v, ne = 1;
    int min, mincost = 0, cost[10][10];

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // 999 represents infinity
        }
    }

    printf("\nThe edges of the Minimum Cost Spanning Tree are:\n");

    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("\nEdge %d: (%d -> %d)\tCost: %d", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n\nMinimum cost = %d\n", mincost);
    return 0;
}
