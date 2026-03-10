#include <stdio.h>
#define MAX 100

int queue[MAX];
int size = 0;

void insert(int x) {
    if (size == MAX) return;
    queue[size++] = x;
}

int delete() {
    if (size == 0) return -1;
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (queue[i] < queue[minIndex]) minIndex = i;
    }
    int val = queue[minIndex];
    for (int i = minIndex; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }
    size--;
    return val;
}

int peek() {
    if (size == 0) return -1;
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (queue[i] < queue[minIndex]) minIndex = i;
    }
    return queue[minIndex];
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char op[10];
        int x;
        scanf("%s", op);
        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') {
            printf("%d\n", delete());
        } else if (op[0] == 'p') {
            printf("%d\n", peek());
        }
    }
    return 0;
}