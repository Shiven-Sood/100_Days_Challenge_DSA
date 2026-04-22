#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex, dist;
};

struct MinHeap {
    struct Node *arr;
    int size, capacity;
};

struct MinHeap* createHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->arr = (struct Node*)malloc(capacity * sizeof(struct Node));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a; *a = *b; *b = temp;
}

void heapifyUp(struct MinHeap* heap, int idx) {
    while (idx && heap->arr[(idx-1)/2].dist > heap->arr[idx].dist) {
        swap(&heap->arr[idx], &heap->arr[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}

void heapifyDown(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx+1, right = 2*idx+2;
    if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist) smallest = left;
    if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist) smallest = right;
    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void push(struct MinHeap* heap, int v, int d) {
    heap->arr[heap->size].vertex = v;
    heap->arr[heap->size].dist = d;
    heap->size++;
    heapifyUp(heap, heap->size-1);
}

struct Node pop(struct MinHeap* heap) {
    struct Node root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size-1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **adj = (int **)malloc((n+1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        adj[i] = (int *)malloc((n+1) * sizeof(int));
        for (int j = 0; j <= n; j++) adj[i][j] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // undirected
    }

    int source;
    scanf("%d", &source);

    int *dist = (int *)malloc((n+1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[source] = 0;

    struct MinHeap* heap = createHeap(n*m);
    push(heap, source, 0);

    while (!isEmpty(heap)) {
        struct Node node = pop(heap);
        int u = node.vertex;
        int d = node.dist;
        if (d > dist[u]) continue;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v]) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    push(heap, v, dist[v]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}