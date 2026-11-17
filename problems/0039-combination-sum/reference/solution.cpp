class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        auto visit = [&](auto &&self, int start, int remaining) -> void {
            if (remaining == 0) {
                result.push_back(path);
                return;
            }
            for (int i = start; i < static_cast<int>(nums.size()); i++) {
                int value = nums[i];
                if (value > remaining) {
                    break;
                }
                path.push_back(value);
                self(self, i, remaining - value);
                path.pop_back();
            }
        };
        visit(visit, 0, target);
        return result;
    }
};
