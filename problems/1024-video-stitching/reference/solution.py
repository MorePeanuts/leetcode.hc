class Solution:
    def videoStitching(self, clips: list[list[int]], time: int) -> int:
        ends = [0] * time
        for start, end in clips:
            if start < time:
                ends[start] = max(ends[start], end)

        used = covered = farthest = 0
        for start, end in enumerate(ends):
            farthest = max(farthest, end)
            if start == covered:
                if farthest == covered:
                    return -1
                covered = farthest
                used += 1
        return used
