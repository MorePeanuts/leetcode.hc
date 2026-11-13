class Solution:
    def findMaxLength(self, nums: list[int]) -> int:
        first = {0: -1}
        balance = answer = 0
        for index, value in enumerate(nums):
            balance += 1 if value == 1 else -1
            if balance in first:
                answer = max(answer, index - first[balance])
            else:
                first[balance] = index
        return answer
