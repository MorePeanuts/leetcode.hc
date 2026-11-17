class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> first{{0, -1}};
        int remainder = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            remainder = (static_cast<long long>(remainder) + nums[i]) % k;
            auto [it, inserted] = first.emplace(remainder, i);
            if (!inserted && i - it->second >= 2) {
                return true;
            }
        }
        return false;
    }
};
