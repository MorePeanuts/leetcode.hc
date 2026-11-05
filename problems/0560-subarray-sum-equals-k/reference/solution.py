class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        # Prefix sums: a subarray ending here sums to k when an earlier
        # prefix equals the current prefix minus k. O(n).
        seen = {0: 1}
        prefix = 0
        count = 0
        for x in nums:
            prefix += x
            count += seen.get(prefix - k, 0)
            seen[prefix] = seen.get(prefix, 0) + 1
        return count
