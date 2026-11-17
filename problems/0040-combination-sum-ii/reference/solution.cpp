class Solution {
    void visit(const std::vector<int>& values, int size, std::vector<std::vector<int>>& result, std::vector<int>& path, int start, int remaining) {
        if (remaining == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < size; ++i) {
            int value = values[i];
            if (value > remaining) {
                break;
            }
            if (i > start && value == values[i - 1]) {
                continue;
            }
            path.push_back(value);
            visit(values, size, result, path, i + 1, remaining - value);
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& values, int target) {
        std::sort(values.begin(), values.end());
        int size = static_cast<int>(values.size());
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        visit(values, size, result, path, 0, target);
        return result;
    }
};
