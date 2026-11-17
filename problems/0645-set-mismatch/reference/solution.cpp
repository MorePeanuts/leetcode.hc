class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size();
        vector<bool> seen(n + 1);
        int total = 0;
        int duplicate = 0;
        for (int i = 0; i < n; i++) {
            int value = nums[i];
            total += value;
            if (seen[value]) {
                duplicate = value;
            }
            seen[value] = true;
        }
        int missing = n * (n + 1) / 2 - total + duplicate;
        return {duplicate, missing};
    }
};
