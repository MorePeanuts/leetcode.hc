class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        k = 0
        for value in nums:
            if k < 2 or value != nums[k - 2]:
                nums[k] = value
                k += 1
        return k
