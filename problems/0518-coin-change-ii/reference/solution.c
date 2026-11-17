#include <limits.h>

int change(int amount, int* coins, int coinsSize) {
    int ways[5001] = {0}; // amount <= 5000
    ways[0] = 1;
    for (int i = 0; i < coinsSize; i++) {
        int coin = coins[i];
        for (int total = coin; total <= amount; total++) {
            ways[total] = ways[total] > INT_MAX - ways[total - coin] ? INT_MAX : ways[total] + ways[total - coin];
        }
    }
    return ways[amount];
}
