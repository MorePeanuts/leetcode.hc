class Solution:
    def numDecodings(self, s: str) -> int:
        two_back, one_back = 1, int(s[0] != "0")
        for i in range(1, len(s)):
            current = one_back if s[i] != "0" else 0
            if "10" <= s[i-1:i+1] <= "26":
                current += two_back
            two_back, one_back = one_back, current
        return one_back
