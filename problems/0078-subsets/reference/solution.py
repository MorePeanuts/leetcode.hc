class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        result = [[]]
        for value in nums:
            result += [subset + [value] for subset in result]
        return result
