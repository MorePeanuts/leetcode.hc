class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        # The rows read one after another form one sorted array of m * n
        # values: binary search it, mapping index i to matrix[i // n][i % n].
        m, n = len(matrix), len(matrix[0])
        lo, hi = 0, m * n - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            value = matrix[mid // n][mid % n]
            if value == target:
                return True
            if value < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return False
