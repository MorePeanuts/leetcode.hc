class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> path;
        auto visit = [&](auto &&self, int start) -> void {
            result.push_back(path);
            for (int i = start; i < static_cast<int>(nums.size()); i++) {
                path.push_back(nums[i]);
                self(self, i + 1);
                path.pop_back();
            }
        };
        visit(visit, 0);
        return result;
    }
};
