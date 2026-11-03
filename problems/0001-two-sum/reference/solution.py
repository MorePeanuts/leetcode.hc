class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen: dict[int, int] = {}
        for i, x in enumerate(nums):
            j = seen.get(target - x)
            if j is not None:
                return [j, i]
            seen[x] = i
        return []
