#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);

    int **adj = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        adj[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) adj[i][j] = 0;
    }

    for (int i = 0; i < m; i++)
     {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;  
    }

    int *key = (int *)malloc((n + 1) * sizeof(int));
    int *mstSet = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0; 
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1, min = INT_MAX;
        for (int v = 1; v <= n; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        mstSet[u] = 1;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}