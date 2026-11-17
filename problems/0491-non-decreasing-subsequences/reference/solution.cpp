class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> path;
        auto visit = [&](auto &&self, int start) -> void {
            if (path.size() >= 2) {
                result.push_back(path);
            }
            bool seen[201] = {};
            for (int i = start; i < static_cast<int>(nums.size()); i++) {
                int value = nums[i];
                if ((!path.empty() && value < path.back()) || seen[value + 100]) {
                    continue;
                }
                seen[value + 100] = true;
                path.push_back(value);
                self(self, i + 1);
                path.pop_back();
            }
        };
        visit(visit, 0);
        return result;
    }
};
