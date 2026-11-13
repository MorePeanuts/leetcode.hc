class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        left = zeros = answer = 0
        for right, value in enumerate(nums):
            zeros += value == 0
            while zeros > k:
                zeros -= nums[left] == 0
                left += 1
            answer = max(answer, right - left + 1)
        return answer
