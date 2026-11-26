class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        k = 0
        for value in nums:
            if k == 0 or nums[k - 1] != value:
                nums[k] = value
                k += 1
        return k
