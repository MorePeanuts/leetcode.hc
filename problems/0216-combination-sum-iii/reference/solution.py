class Solution:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        result = []
        path = []

        def visit(start, remaining):
            needed = k - len(path)
            if needed == 0:
                if remaining == 0:
                    result.append(path.copy())
                return
            for digit in range(start, min(10 - needed, remaining) + 1):
                path.append(digit)
                visit(digit + 1, remaining - digit)
                path.pop()

        visit(1, n)
        return result
