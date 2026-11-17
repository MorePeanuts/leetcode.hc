#include <algorithm>
#include <vector>

class Solution {
    static int distance(const std::vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return distance(a) < distance(b);
        });
        return {points.begin(), points.begin() + k};
    }
};
