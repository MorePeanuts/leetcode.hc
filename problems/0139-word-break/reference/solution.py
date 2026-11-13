class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        words = set(wordDict)
        longest = max(map(len, wordDict))
        possible = [False] * (len(s) + 1)
        possible[0] = True
        for end in range(1, len(s) + 1):
            for start in range(max(0, end-longest), end):
                if possible[start] and s[start:end] in words:
                    possible[end] = True
                    break
        return possible[-1]
