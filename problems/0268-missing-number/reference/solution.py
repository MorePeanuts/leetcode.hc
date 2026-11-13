class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        missing = len(nums)
        for index, value in enumerate(nums):
            missing ^= index ^ value
        return missing
