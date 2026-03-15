#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Stack {
    int arr[100];
    int top;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

void initStack(struct Stack* s) {
    s->top = -1;
}

void push(struct Stack* s, int val) {
    s->arr[++s->top] = val;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

void reverseQueue(struct Queue* q) {
    struct Stack s;
    initStack(&s);
    while (q->front != NULL) {
        push(&s, dequeue(q));
    }
    while (s.top != -1) {
        enqueue(q, pop(&s));
    }
}

void display(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, val;
    scanf("%d", &n);
    struct Queue q;
    initQueue(&q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }
    reverseQueue(&q);
    display(&q);
    return 0;
}