class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int m = static_cast<int>(s1.size());
        int n = static_cast<int>(s2.size());
        if (m + n != static_cast<int>(s3.size())) {
            return false;
        }
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                bool fromS1 = i > 0 && dp[j] != 0 && s1[i - 1] == s3[i + j - 1];
                bool fromS2 = j > 0 && dp[j - 1] != 0 && s2[j - 1] == s3[i + j - 1];
                dp[j] = fromS1 || fromS2 ? 1 : 0;
            }
        }
        bool answer = dp[n] != 0;
        return answer;
    }
};
