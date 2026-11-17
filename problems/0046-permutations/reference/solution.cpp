class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        auto visit = [&](auto &&self, int start) -> void {
            if (start == static_cast<int>(nums.size())) {
                result.push_back(nums);
                return;
            }
            for (int i = start; i < static_cast<int>(nums.size()); i++) {
                int value = nums[start];
                nums[start] = nums[i];
                nums[i] = value;
                self(self, start + 1);
                nums[i] = nums[start];
                nums[start] = value;
            }
        };
        visit(visit, 0);
        return result;
    }
};
