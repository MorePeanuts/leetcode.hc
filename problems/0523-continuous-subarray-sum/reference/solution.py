class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        first = {0: -1}
        remainder = 0
        for index, value in enumerate(nums):
            remainder = (remainder + value) % k
            if remainder in first:
                if index - first[remainder] >= 2:
                    return True
            else:
                first[remainder] = index
        return False
