
// Write a C program to insert an element x at a given 1-based position pos in an array of n integers.

#include <stdio.h>

int main() {
    int n, pos, x;
    scanf("%d", &n);

    int arr[n + 1];
    int i;

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);
    scanf("%d", &x);

    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    for (i = 0; i < n + 1; i++)
     {
        printf("%d", arr[i]);
        printf(" ");
    }

    return 0;
}