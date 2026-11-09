class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = "".join(filter(str.isalnum, s)).lower()
        return t == t[::-1]
