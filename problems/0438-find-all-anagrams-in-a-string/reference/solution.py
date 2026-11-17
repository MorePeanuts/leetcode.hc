class Solution:
    def findAnagrams(self, s: str, p: str) -> list[int]:
        need, window = [0] * 26, [0] * 26
        for ch in p:
            need[ord(ch) - ord('a')] += 1
        answer = []
        for right, ch in enumerate(s):
            window[ord(ch) - ord('a')] += 1
            if right >= len(p):
                window[ord(s[right - len(p)]) - ord('a')] -= 1
            if right + 1 >= len(p) and window == need:
                answer.append(right + 1 - len(p))
        return answer
