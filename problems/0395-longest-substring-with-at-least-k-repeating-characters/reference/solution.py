from collections import Counter


class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if len(s) < k:
            return 0
        for char, count in Counter(s).items():
            if count < k:
                return max(self.longestSubstring(part, k) for part in s.split(char))
        return len(s)
