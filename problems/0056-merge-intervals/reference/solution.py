class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        # Sort by start, then extend the last merged interval while the next
        # one starts inside it: O(n log n). Returns ascending order.
        merged = []
        for start, end in sorted(intervals):
            if merged and start <= merged[-1][1]:
                if end > merged[-1][1]:
                    merged[-1][1] = end
            else:
                merged.append([start, end])
        return merged
