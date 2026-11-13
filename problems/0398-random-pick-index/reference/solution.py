from collections import defaultdict
from random import choice


class Solution:
    def __init__(self, nums: list[int]):
        self.indices = defaultdict(list)
        for i, value in enumerate(nums):
            self.indices[value].append(i)

    def pick(self, target: int) -> int:
        return choice(self.indices[target])
