class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        best = 0
        stack = []  # indices of bars with increasing heights
        for i, h in enumerate(heights + [0]):
            while stack and heights[stack[-1]] >= h:
                top = stack.pop()
                left = stack[-1] + 1 if stack else 0
                best = max(best, heights[top] * (i - left))
            stack.append(i)
        return best
