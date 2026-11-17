#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

class Solution {
    std::vector<int> prefix;
    std::mt19937 random{std::random_device{}()};

public:
    explicit Solution(std::vector<int>& w) : prefix(w.size()) {
        std::partial_sum(w.begin(), w.end(), prefix.begin());
    }

    int pickIndex() {
        int target = std::uniform_int_distribution<int>(0, prefix.back() - 1)(random);
        return static_cast<int>(std::upper_bound(prefix.begin(), prefix.end(), target) - prefix.begin());
    }
};
