class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # dp over prefixes with two rows: O(m * n) time, O(n) space.
        n = len(word2)
        prev = list(range(n + 1))
        for i, a in enumerate(word1, 1):
            cur = [i] + [0] * n
            for j in range(n):
                if a == word2[j]:
                    cur[j + 1] = prev[j]
                else:
                    best = prev[j]
                    if prev[j + 1] < best:
                        best = prev[j + 1]
                    if cur[j] < best:
                        best = cur[j]
                    cur[j + 1] = best + 1
            prev = cur
        return prev[n]
