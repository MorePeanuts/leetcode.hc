#include <unordered_map>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> last;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            auto [entry, inserted] = last.try_emplace(nums[i], i);
            if (!inserted && i - entry->second <= k) return true;
            entry->second = i;
        }
        return false;
    }
};
