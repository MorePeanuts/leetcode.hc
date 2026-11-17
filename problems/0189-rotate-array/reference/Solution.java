class Solution {
    private void reverseRange(int[] nums, int left, int right) {
        while (left < right) {
            int value = nums[left];
            nums[left++] = nums[right];
            nums[right--] = value;
        }
    }

    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        reverseRange(nums, 0, n - 1);
        reverseRange(nums, 0, k - 1);
        reverseRange(nums, k, n - 1);
    }
}
