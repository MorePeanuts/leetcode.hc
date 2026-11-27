class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        auto visit = [&](auto&& self, int start, int needed) -> void {
            if (needed == 0) {
                result.push_back(path);
                return;
            }
            for (int value = start; value <= n - needed + 1; value++) {
                path.push_back(value);
                self(self, value + 1, needed - 1);
                path.pop_back();
            }
        };
        visit(visit, 1, k);
        return result;
    }
};
