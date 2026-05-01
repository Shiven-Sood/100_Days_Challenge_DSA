#include <stdio.h>

// Check if possible within given maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxTime)
            return 0;

        if(time + arr[i] > maxTime) {
            painters++;
            time = arr[i];
        } else {
            time += arr[i];
        }
    }

    return (painters <= k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

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

        if(isPossible(arr, n, k, mid)) {
            ans = mid;        // try smaller time
            right = mid - 1;
        } else {
            left = mid + 1;   // need more time
        }
    }

    printf("%d", ans);
    return 0;
}
