#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if (empty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

void push_front(int x) {
    if ((rear + 1) % MAX == front) return;
    if (empty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    deque[front] = x;
}

void push_back(int x) {
    if ((rear + 1) % MAX == front) return;
    if (empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    deque[rear] = x;
}

int pop_front() {
    if (empty()) return -1;
    int val = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return val;
}

int pop_back() {
    if (empty()) return -1;
    int val = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
    return val;
}

int get_front() {
    if (empty()) return -1;
    return deque[front];
}

int get_back() {
    if (empty()) return -1;
    return deque[rear];
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    printf("%d\n", get_front()); // 5
    printf("%d\n", get_back());  // 20
    printf("%d\n", pop_front()); // 5
    printf("%d\n", pop_back());  // 20
    printf("%d\n", size());      // 1
    return 0;
}