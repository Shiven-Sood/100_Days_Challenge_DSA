#include <stdio.h>

// Partition function (Hoare)
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // first element as pivot
    int i = low - 1;
    int j = high + 1;

    while (1) {
        // move right until element >= pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // move left until element <= pivot
        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        // swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Main
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
