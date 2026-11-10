class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # need[c] is how many more c the window needs (negative: spare ones),
        # missing the number of t's characters it still lacks.
        need = [0] * 128
        for ch in t:
            need[ord(ch)] += 1
        missing = len(t)
        left = 0
        best_start, best_len = 0, len(s) + 1
        for right, ch in enumerate(s):
            c = ord(ch)
            if need[c] > 0:
                missing -= 1
            need[c] -= 1
            if missing == 0:
                # Drop spare characters from the left: the window ending at
                # right is then the shortest one.
                while need[ord(s[left])] < 0:
                    need[ord(s[left])] += 1
                    left += 1
                if right - left + 1 < best_len:
                    best_start, best_len = left, right - left + 1
                # Give up the leftmost character, which the window needs.
                need[ord(s[left])] += 1
                missing += 1
                left += 1
        return s[best_start:best_start + best_len] if best_len <= len(s) else ""
