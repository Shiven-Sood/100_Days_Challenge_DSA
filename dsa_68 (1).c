#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], indegree[MAX], n;

void topologicalSort() {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) queue[rear++] = v;
            }
        }
    }
}

int main() {
    int e, u, v;
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }
    topologicalSort();
    return 0;
}