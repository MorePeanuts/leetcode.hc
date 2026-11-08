class Solution:
    def sortArray(self, nums: list[int]) -> list[int]:
        def sift_down(root: int, end: int) -> None:
            value = nums[root]
            child = 2 * root + 1
            while child < end:
                if child + 1 < end and nums[child] < nums[child + 1]:
                    child += 1
                if nums[child] <= value:
                    break
                nums[root] = nums[child]
                root = child
                child = 2 * root + 1
            nums[root] = value

        n = len(nums)
        for root in range(n // 2 - 1, -1, -1):
            sift_down(root, n)
        for end in range(n - 1, 0, -1):
            nums[0], nums[end] = nums[end], nums[0]
            sift_down(0, end)
        return nums
