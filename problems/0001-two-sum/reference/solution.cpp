class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        seen.reserve(nums.size());
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto match = seen.find(target - nums[i]);
            if (match != seen.end()) {
                return {match->second, i};
            }
            seen.emplace(nums[i], i);
        }
        return {};
    }
};
