class Solution:
    def rob(self, nums: list[int]) -> int:
        two_back = one_back = 0
        for money in nums:
            two_back, one_back = one_back, max(one_back, two_back + money)
        return one_back
