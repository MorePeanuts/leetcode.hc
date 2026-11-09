class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # A window that never shrinks: it grows only when the most frequent
        # letter seen in a window reaches a new high, so its size ends as
        # the answer.
        count = [0] * 26
        most = 0
        left = 0
        for right, ch in enumerate(s):
            i = ord(ch) - 65
            count[i] += 1
            if count[i] > most:
                most = count[i]
            if right - left + 1 - most > k:
                count[ord(s[left]) - 65] -= 1
                left += 1
        return len(s) - left
