class Solution {
    public void sortColors(int[] nums) {
        int low = 0;
        int scan = 0;
        int high = nums.length - 1;
        while (scan <= high) {
            if (nums[scan] == 0) {
                nums[scan++] = nums[low];
                nums[low++] = 0;
            } else if (nums[scan] == 2) {
                nums[scan] = nums[high];
                nums[high--] = 2;
            } else {
                ++scan;
            }
        }
    }
}
