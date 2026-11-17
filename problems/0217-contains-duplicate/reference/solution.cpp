class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());
        for (int value : nums) {
            if (!seen.insert(value).second) {
                return true;
            }
        }
        return false;
    }
};
