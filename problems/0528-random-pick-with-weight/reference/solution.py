from bisect import bisect_right
from itertools import accumulate
from random import randrange


class Solution:
    def __init__(self, w: list[int]):
        self.prefix = list(accumulate(w))

    def pickIndex(self) -> int:
        return bisect_right(self.prefix, randrange(self.prefix[-1]))
