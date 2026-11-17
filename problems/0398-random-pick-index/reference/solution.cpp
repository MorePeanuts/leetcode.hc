#include <random>

class Solution {
    unordered_map<int, vector<int>> positions;
    std::mt19937 random{std::random_device{}()};

public:
    Solution(vector<int> &nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            positions[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        const auto &indices = positions.at(target);
        std::uniform_int_distribution<size_t> sample(0, indices.size() - 1);
        return indices[sample(random)];
    }
};
