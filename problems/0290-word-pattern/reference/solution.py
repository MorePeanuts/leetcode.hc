class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(words) != len(pattern):
            return False
        forward, reverse = {}, {}
        for char, word in zip(pattern, words):
            if char in forward and forward[char] != word:
                return False
            if word in reverse and reverse[word] != char:
                return False
            forward[char] = word
            reverse[word] = char
        return True
