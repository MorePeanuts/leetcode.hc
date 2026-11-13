class Solution:
    def findErrorNums(self, nums: list[int]) -> list[int]:
        seen = set()
        duplicate = 0
        total = 0
        for value in nums:
            total += value
            if value in seen:
                duplicate = value
            seen.add(value)
        n = len(nums)
        missing = n * (n + 1) // 2 - total + duplicate
        return [duplicate, missing]
