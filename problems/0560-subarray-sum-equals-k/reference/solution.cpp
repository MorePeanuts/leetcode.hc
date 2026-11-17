#include <unordered_map>
#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> seen{{0, 1}};
        int prefix = 0;
        int answer = 0;
        for (int value : nums) {
            prefix += value;
            auto entry = seen.find(prefix - k);
            if (entry != seen.end()) answer += entry->second;
            ++seen[prefix];
        }
        return answer;
    }
};
