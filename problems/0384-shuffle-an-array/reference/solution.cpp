#include <algorithm>
#include <random>
#include <vector>

class Solution {
    std::vector<int> original;
    std::mt19937 random{std::random_device{}()};

public:
    explicit Solution(std::vector<int>& nums) : original(nums) {}

    std::vector<int> reset() {
        return original;
    }

    std::vector<int> shuffle() {
        auto result = original;
        std::shuffle(result.begin(), result.end(), random);
        return result;
    }
};
