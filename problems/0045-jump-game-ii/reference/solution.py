class Solution:
    def jump(self, nums: list[int]) -> int:
        jumps = end = farthest = 0
        for index in range(len(nums) - 1):
            farthest = max(farthest, index + nums[index])
            if index == end:
                jumps += 1
                end = farthest
        return jumps
