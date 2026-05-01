#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxPages)
            return 0;

        if(pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];
        } else {
            pages += arr[i];
        }
    }

    return (students <= m);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int sum = 0, maxVal = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }

    int left = maxVal;
    int right = sum;
    int ans = right;

    // Binary Search
    while(left <= right) {
        int mid = (left + right) / 2;

        if(isPossible(arr, n, m, mid)) {
            ans = mid;        // valid, try smaller
            right = mid - 1;
        } else {
            left = mid + 1;   // increase pages
        }
    }

    printf("%d", ans);
    return 0;
}
