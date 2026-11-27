class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        auto visit = [&](auto&& self, int start, int needed, int remaining) -> void {
            if (needed == 0) {
                if (remaining == 0) {
                    result.push_back(path);
                }
                return;
            }
            for (int value = start; value <= 9 - needed + 1 && value <= remaining; value++) {
                path.push_back(value);
                self(self, value + 1, needed - 1, remaining - value);
                path.pop_back();
            }
        };
        visit(visit, 1, k, n);
        return result;
    }
};
