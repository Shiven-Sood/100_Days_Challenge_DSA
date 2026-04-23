#include <stdio.h>
#include <limits.h>

#define INF 1000000000  
int main() {
    int n;
    scanf("%d", &n);

    int dist[n][n];

    // Read adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            scanf("%d", &w);
            if (w == -1 && i != j) dist[i][j] = INF;
            else dist[i][j] = w;
        }
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF/2) printf("-1 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}