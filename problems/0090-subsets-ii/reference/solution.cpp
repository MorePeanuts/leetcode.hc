class Solution {
    void visit(const std::vector<int>& values, int size, std::vector<std::vector<int>>& result, std::vector<int>& path, int start) {
        result.push_back(path);
        for (int i = start; i < size; ++i) {
            int value = values[i];

            if (i > start && value == values[i - 1]) {
                continue;
            }
            path.push_back(value);
            visit(values, size, result, path, i + 1);
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& values) {
        std::sort(values.begin(), values.end());
        int size = static_cast<int>(values.size());
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        visit(values, size, result, path, 0);
        return result;
    }
};
