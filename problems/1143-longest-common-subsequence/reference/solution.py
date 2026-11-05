class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # dp over prefixes with two rows: O(m * n) time, O(n) space.
        n = len(text2)
        prev = [0] * (n + 1)
        for a in text1:
            cur = [0] * (n + 1)
            for j in range(n):
                if a == text2[j]:
                    cur[j + 1] = prev[j] + 1
                elif prev[j + 1] >= cur[j]:
                    cur[j + 1] = prev[j + 1]
                else:
                    cur[j + 1] = cur[j]
            prev = cur
        return prev[n]
