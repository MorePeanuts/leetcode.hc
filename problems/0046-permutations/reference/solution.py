class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        answer = []
        def search(start):
            if start == len(nums):
                answer.append(nums.copy())
                return
            for i in range(start, len(nums)):
                nums[start], nums[i] = nums[i], nums[start]
                search(start + 1)
                nums[start], nums[i] = nums[i], nums[start]
        search(0)
        return answer
