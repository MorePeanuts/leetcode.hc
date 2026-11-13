class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        answer = []
        columns = set()
        descending = set()
        ascending = set()
        placement = []
        def search(row):
            if row == n:
                answer.append(["." * col + "Q" + "." * (n - col - 1) for col in placement])
                return
            for col in range(n):
                if col in columns or row-col in descending or row+col in ascending:
                    continue
                columns.add(col)
                descending.add(row-col)
                ascending.add(row+col)
                placement.append(col)
                search(row+1)
                placement.pop()
                columns.remove(col)
                descending.remove(row-col)
                ascending.remove(row+col)
        search(0)
        return answer
