#include <stdio.h>

int lower_bound(int arr[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int upper_bound(int arr[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main() {
    int n, x;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);

    int lb = lower_bound(arr, n, x);
    int ub = upper_bound(arr, n, x);

    printf("%d %d\n", lb, ub);
    return 0;
}