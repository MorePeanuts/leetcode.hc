class Solution:
    def numTrees(self, n):
        count = [0] * (n + 1)
        count[0] = 1
        for size in range(1, n + 1):
            count[size] = sum(count[left] * count[size - 1 - left] for left in range(size))
        return count[n]
