#include <climits>
#include <vector>

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<int> ways(amount + 1);
        ways[0] = 1;
        for (int i = 0; i < static_cast<int>(coins.size()); i++) {
            int coin = coins[i];
            for (int total = coin; total <= amount; total++) {
                ways[total] = ways[total] > INT_MAX - ways[total - coin] ? INT_MAX : ways[total] + ways[total - coin];
            }
        }
        return ways[amount];
    }
};
