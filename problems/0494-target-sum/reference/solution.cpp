class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int total = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            total += nums[i];
        }
        if (target > total || target < -total || ((total + target) & 1) != 0) {
            return 0;
        }
        int goal = (total + target) >> 1;
        std::vector<int> ways(goal + 1);
        ways[0] = 1;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int value = nums[i];
            for (int subtotal = goal; subtotal >= value; --subtotal) {
                ways[subtotal] += ways[subtotal - value];
            }
        }
        int answer = ways[goal];
        return answer;
    }
};
