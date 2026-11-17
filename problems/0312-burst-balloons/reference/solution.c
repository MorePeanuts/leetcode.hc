#include <stdlib.h>

int maxCoins(int* nums, int numsSize) {
    int n = numsSize + 2;
    int values[302]; // numsSize <= 300
    int* storage = calloc((size_t)n * n, sizeof(*storage));
    int* dp[302];
    for (int i = 0; i < n; i++) dp[i] = storage + i * n;
    values[0] = values[n - 1] = 1;
    for (int i = 1; i < n - 1; i++) values[i] = nums[i - 1];
    for (int left = n - 3; left >= 0; left--) {
        for (int right = left + 2; right < n; right++) {
            int boundary = values[left] * values[right];
            int best = 0;
            for (int last = left + 1; last < right; last++) {
                int coins = dp[left][last] + dp[last][right] + boundary * values[last];
                if (coins > best) best = coins;
            }
            dp[left][right] = best;
        }
    }
    int answer = dp[0][n - 1];
    free(storage);
    return answer;
}
