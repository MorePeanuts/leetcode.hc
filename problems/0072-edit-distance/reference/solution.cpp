class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = static_cast<int>(word1.size());
        int n = static_cast<int>(word2.size());
        std::vector<int> dp(n + 1);
        for (int j = 0; j <= n; ++j) {
            dp[j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            int diagonal = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                int above = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = diagonal;
                } else {
                    int best = dp[j - 1] < above ? dp[j - 1] : above;
                    dp[j] = (best < diagonal ? best : diagonal) + 1;
                }
                diagonal = above;
            }
        }
        int answer = dp[n];
        return answer;
    }
};
