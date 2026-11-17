class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        for (int value : nums) {
            ++counts[value];
        }
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (const auto& [value, frequency] : counts) {
            buckets[frequency].push_back(value);
        }
        std::vector<int> result;
        result.reserve(k);
        for (int f = static_cast<int>(nums.size()); f > 0 && static_cast<int>(result.size()) < k; --f) {
            for (int value : buckets[f]) {
                result.push_back(value);
                if (static_cast<int>(result.size()) == k) {
                    break;
                }
            }
        }
        return result;
    }
};
