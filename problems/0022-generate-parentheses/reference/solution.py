class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        result = []
        path = []
        def search(opened, closed):
            if closed == n:
                result.append("".join(path))
                return
            if opened < n:
                path.append("(")
                search(opened + 1, closed)
                path.pop()
            if closed < opened:
                path.append(")")
                search(opened, closed + 1)
                path.pop()
        search(0, 0)
        return result
