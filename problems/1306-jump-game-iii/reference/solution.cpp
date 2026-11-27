class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> seen(n);
        vector<int> stack{start};
        seen[start] = true;
        while (!stack.empty()) {
            int i = stack.back();
            stack.pop_back();
            if (arr[i] == 0) return true;
            for (int j : {i - arr[i], i + arr[i]}) {
                if (j >= 0 && j < n && !seen[j]) {
                    seen[j] = true;
                    stack.push_back(j);
                }
            }
        }
        return false;
    }
};
