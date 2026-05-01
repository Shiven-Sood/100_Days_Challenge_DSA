#include <stdio.h>
#include <stdlib.h>

#define N 10   // number of buckets

// structure for linked list node
struct Node {
    float data;
    struct Node* next;
};

// insert element into bucket in sorted order
struct Node* insertSorted(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    struct Node* curr = head;
    while (curr->next != NULL && curr->next->data < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

// bucket sort function
void bucketSort(float arr[], int n) {
    struct Node* buckets[N];

    // initialize buckets
    for (int i = 0; i < N; i++)
        buckets[i] = NULL;

    // distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * N;
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    // concatenate buckets
    int k = 0;
    for (int i = 0; i < N; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }
}

// main function
int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}
