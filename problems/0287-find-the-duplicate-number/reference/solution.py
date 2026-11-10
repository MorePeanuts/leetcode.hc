class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        # Floyd's cycle detection on i -> nums[i]: index 0 is never a target,
        # so the walk from it enters a cycle, whose entrance is the duplicate.
        slow = fast = 0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        slow = 0
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        return slow
