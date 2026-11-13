class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        smallest = largest = answer = nums[0]
        for value in nums[1:]:
            smallest, largest = min(value, value*smallest, value*largest), max(value, value*smallest, value*largest)
            answer = max(answer, largest)
        return answer
