class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        k = 0
        for value in nums:
            if value != val:
                nums[k] = value
                k += 1
        return k
