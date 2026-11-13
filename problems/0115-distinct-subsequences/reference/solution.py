class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        ways = [0] * (len(t) + 1)
        ways[0] = 1
        for char in s:
            for j in range(len(t), 0, -1):
                if char == t[j - 1]:
                    ways[j] += ways[j - 1]
        return ways[-1]
