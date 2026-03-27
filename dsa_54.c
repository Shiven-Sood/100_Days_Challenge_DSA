#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue 
{
    struct Node** arr;
    int front, rear, size;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);
    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct Node* node = dequeue(q);
        if (arr[i] != -1) {
            node->left = newNode(arr[i]);
            enqueue(q, node->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            node->right = newNode(arr[i]);
            enqueue(q, node->right);
        }
        i++;
    }
    return root;
}

void zigzagTraversal(struct Node* root) {
    if (!root) return;
    struct Queue* q = createQueue(1000);
    enqueue(q, root);
    int leftToRight = 1;

    while (!isEmpty(q)) {
        int levelSize = q->rear - q->front;
        int* level = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct Node* node = dequeue(q);
            int index = leftToRight ? i : (levelSize - 1 - i);
            level[index] = node->data;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        for (int i = 0; i < levelSize; i++) {
            printf("%d ", level[i]);
        }
        free(level);
        leftToRight = !leftToRight;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);
    zigzagTraversal(root);

    return 0;
}