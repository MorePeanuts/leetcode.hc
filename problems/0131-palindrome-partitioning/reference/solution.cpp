class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> palindrome(n, vector<bool>(n));
        for (int left = n - 1; left >= 0; left--) {
            for (int right = left; right < n; right++) {
                palindrome[left][right] = s[left] == s[right] &&
                    (right - left < 2 || palindrome[left + 1][right - 1]);
            }
        }
        vector<vector<string>> answer;
        vector<string> path;
        auto visit = [&](auto &&self, int start) -> void {
            if (start == n) {
                answer.push_back(path);
                return;
            }
            for (int end = start; end < n; end++) {
                if (palindrome[start][end]) {
                    path.push_back(s.substr(start, end - start + 1));
                    self(self, end + 1);
                    path.pop_back();
                }
            }
        };
        visit(visit, 0);
        return answer;
    }
};
