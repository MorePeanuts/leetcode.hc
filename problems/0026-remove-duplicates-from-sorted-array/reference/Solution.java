class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        for (int value : nums) {
            if (k == 0 || nums[k - 1] != value) {
                nums[k++] = value;
            }
        }
        return k;
    }
}
