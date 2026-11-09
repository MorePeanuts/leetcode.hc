class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m, n = len(s1), len(s2)
        if m > n:
            return False
        need = [0] * 26
        window = [0] * 26
        for ch in s1:
            need[ord(ch) - 97] += 1
        for ch in s2[:m]:
            window[ord(ch) - 97] += 1
        if window == need:
            return True
        for i in range(m, n):
            window[ord(s2[i]) - 97] += 1
            window[ord(s2[i - m]) - 97] -= 1
            if window == need:
                return True
        return False
