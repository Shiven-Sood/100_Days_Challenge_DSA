#include <stdio.h>
#include <string.h>

int longestZeroSum(int arr[], int n) {
    int prefixSum[n], index[10000];
    memset(index, -1, sizeof(index));
    int sum = 0, maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) maxLen = i + 1;
        if (index[sum + 5000] != -1) {
            int len = i - index[sum + 5000];
            if (len > maxLen) maxLen = len;
        } else index[sum + 5000] = i;
    }
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", longestZeroSum(arr, n));
    return 0;
}