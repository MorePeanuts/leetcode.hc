from random import shuffle


class Solution:
    def __init__(self, nums: list[int]):
        self.original = nums.copy()

    def reset(self) -> list[int]:
        return self.original.copy()

    def shuffle(self) -> list[int]:
        result = self.original.copy()
        shuffle(result)
        return result
