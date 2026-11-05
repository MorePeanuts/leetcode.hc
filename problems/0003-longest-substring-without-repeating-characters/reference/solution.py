class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last = {}
        best = 0
        start = 0
        for i, c in enumerate(s):
            if c in last and last[c] >= start:
                start = last[c] + 1
            last[c] = i
            if i - start + 1 > best:
                best = i - start + 1
        return best
