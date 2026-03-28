#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Queue {
    struct Node **arr;
    int front, rear, size;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
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
        struct Node* curr = dequeue(q);
        if (curr) {
            curr->left = newNode(arr[i++]);
            if (curr->left) enqueue(q, curr->left);
            if (i < n) {
                curr->right = newNode(arr[i++]);
                if (curr->right) enqueue(q, curr->right);
            }
        }
    }
    return root;
}

void rightView(struct Node* root) {
    if (!root) return;
    struct Queue* q = createQueue(1000);
    enqueue(q, root);
    while (!isEmpty(q)) {
        int count = q->rear - q->front;
        for (int i = 0; i < count; i++) {
            struct Node* curr = dequeue(q);
            if (i == count - 1)
                printf("%d ", curr->data);
            if (curr->left) enqueue(q, curr->left);
            if (curr->right) enqueue(q, curr->right);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, N);
    rightView(root);
    return 0;
}