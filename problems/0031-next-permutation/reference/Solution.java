class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int pivot = n - 2;
        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) {
            pivot--;
        }
        if (pivot >= 0) {
            int successor = n - 1;
            while (nums[successor] <= nums[pivot]) {
                successor--;
            }
            int value = nums[pivot];
            nums[pivot] = nums[successor];
            nums[successor] = value;
        }
        int left = pivot + 1;
        int right = n - 1;
        while (left < right) {
            int value = nums[left];
            nums[left++] = nums[right];
            nums[right--] = value;
        }
    }
}
