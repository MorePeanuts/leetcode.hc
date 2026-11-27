from collections import Counter


class Solution:
    def permuteUnique(self, nums: list[int]) -> list[list[int]]:
        counts = Counter(nums)
        path = []
        result = []

        def visit():
            if len(path) == len(nums):
                result.append(path.copy())
                return
            for value in counts:
                if counts[value]:
                    counts[value] -= 1
                    path.append(value)
                    visit()
                    path.pop()
                    counts[value] += 1

        visit()
        return result
