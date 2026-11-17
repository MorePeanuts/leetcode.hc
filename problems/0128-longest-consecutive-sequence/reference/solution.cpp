class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int best = 0;
        for (int value : values) {
            if (value != INT_MIN && values.count(value - 1) != 0) {
                continue;
            }
            int length = 1;
            while (value != INT_MAX && values.count(value + 1) != 0) {
                value++;
                length++;
            }
            best = max(best, length);
        }
        return best;
    }
};
