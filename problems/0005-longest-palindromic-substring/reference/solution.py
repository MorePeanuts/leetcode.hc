class Solution:
    def longestPalindrome(self, s: str) -> str:
        # Expand around each of the 2n - 1 centers; keeps the leftmost longest
        # palindrome. O(n^2).
        n = len(s)
        best_lo, best_hi = 0, 1
        for center in range(2 * n - 1):
            lo = center // 2
            hi = lo + center % 2
            while lo >= 0 and hi < n and s[lo] == s[hi]:
                lo -= 1
                hi += 1
            if hi - lo - 1 > best_hi - best_lo:
                best_lo, best_hi = lo + 1, hi
        return s[best_lo:best_hi]
