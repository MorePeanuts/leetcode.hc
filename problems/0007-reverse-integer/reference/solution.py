class Solution:
    def reverse(self, x: int) -> int:
        # Keep both the remaining input and result nonpositive: abs(INT_MIN)
        # cannot be represented in a signed 32-bit integer.
        negative = x < 0
        remaining = x if negative else -x
        answer = 0
        last_digit = -8 if negative else -7
        while remaining:
            # Python // rounds down; adjust to division truncated toward zero.
            quotient = remaining // 10
            if remaining % 10:
                quotient += 1
            digit = remaining - quotient * 10
            if answer < -214748364 or (answer == -214748364 and digit < last_digit):
                return 0
            answer = answer * 10 + digit
            remaining = quotient
        return answer if negative else -answer
