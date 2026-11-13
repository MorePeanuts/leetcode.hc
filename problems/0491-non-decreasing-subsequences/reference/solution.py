class Solution:
    def findSubsequences(self, nums: list[int]) -> list[list[int]]:
        answer = []
        path = []
        def visit(start):
            if len(path) >= 2:
                answer.append(path[:])
            used = set()
            for i in range(start, len(nums)):
                value = nums[i]
                if value in used or (path and value < path[-1]):
                    continue
                used.add(value)
                path.append(value)
                visit(i + 1)
                path.pop()
        visit(0)
        return answer
