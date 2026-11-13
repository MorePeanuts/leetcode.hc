from functools import cache


class Solution:
    def diffWaysToCompute(self, expression):
        @cache
        def solve(text):
            answers = []
            for i, ch in enumerate(text):
                if ch in "+-*":
                    for left in solve(text[:i]):
                        for right in solve(text[i + 1:]):
                            if ch == "+":
                                answers.append(left + right)
                            elif ch == "-":
                                answers.append(left - right)
                            else:
                                answers.append(left * right)
            return tuple(answers) if answers else (int(text),)
        return list(solve(expression))
