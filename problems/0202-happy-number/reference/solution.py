class Solution:
    def isHappy(self, n: int) -> bool:
        def step(value):
            total = 0
            while value:
                value, digit = divmod(value, 10)
                total += digit * digit
            return total
        slow, fast = n, step(n)
        while fast != 1 and slow != fast:
            slow = step(slow)
            fast = step(step(fast))
        return fast == 1
