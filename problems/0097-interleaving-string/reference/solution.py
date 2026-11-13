class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        dp = [False] * (len(s2) + 1)
        dp[0] = True
        for i in range(len(s1) + 1):
            for j in range(len(s2) + 1):
                if i == 0 and j == 0:
                    continue
                dp[j] = (i > 0 and dp[j] and s1[i - 1] == s3[i + j - 1]) or (j > 0 and dp[j - 1] and s2[j - 1] == s3[i + j - 1])
        return dp[-1]
