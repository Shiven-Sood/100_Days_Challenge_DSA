#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;
int visited[MAX];

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int n, int adj[][MAX], int s) {
    for(int i=0;i<n;i++) visited[i]=0;
    enqueue(s);
    visited[s]=1;
    while(!isEmpty()) {
        int u=dequeue();
        printf("%d ",u);
        for(int v=0;v<n;v++) {
            if(adj[u][v] && !visited[v]) {
                enqueue(v);
                visited[v]=1;
            }
        }
    }
}

int main() {
    int n,s;
    scanf("%d",&n);
    int adj[MAX][MAX];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    scanf("%d",&s);
    bfs(n,adj,s);
    return 0;
}