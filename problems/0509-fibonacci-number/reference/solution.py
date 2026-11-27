class Solution:
    def fib(self, n: int) -> int:
        current, following = 0, 1
        for _ in range(n):
            current, following = following, current + following
        return current
