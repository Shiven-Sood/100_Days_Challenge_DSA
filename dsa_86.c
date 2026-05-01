#include <stdio.h>

int integerSqrt(int n) {
    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (mid * mid == n) {
            return mid;  // exact square root
        }
        else if (mid * mid < n) {
            ans = mid;      // store possible answer
            left = mid + 1; // move right
        }
        else {
            right = mid - 1; // move left
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", integerSqrt(n));

    return 0;
}
