class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = static_cast<int>(nums.size());
        for (int i = 0; i < static_cast<int>(nums.size()); i++) missing ^= i ^ nums[i];
        return missing;
    }
};
