class Solution:
    def rob(self, nums: list[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        def linear(start, end):
            two_back = one_back = 0
            for i in range(start, end):
                two_back, one_back = one_back, max(one_back, two_back + nums[i])
            return one_back
        return max(linear(0, len(nums)-1), linear(1, len(nums)))
