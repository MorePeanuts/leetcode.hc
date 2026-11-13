class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        candidate, count = 0, 0
        for value in nums:
            if count == 0:
                candidate = value
            count += 1 if value == candidate else -1
        return candidate
