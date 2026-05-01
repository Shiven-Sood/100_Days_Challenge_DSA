#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place cows with minimum distance = dist
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;  // first cow placed
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if(count >= k)
            return 1;
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Step 1: sort stalls
    qsort(stalls, n, sizeof(int), compare);

    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Binary search on answer
    while(left <= right) {
        int mid = (left + right) / 2;

        if(canPlace(stalls, n, k, mid)) {
            ans = mid;        // valid, try bigger
            left = mid + 1;
        } else {
            right = mid - 1;  // reduce distance
        }
    }

    printf("%d", ans);
    return 0;
}
