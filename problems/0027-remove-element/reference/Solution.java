class Solution {
    public int removeElement(int[] nums, int val) {
        int k = 0;
        for (int value : nums) {
            if (value != val) {
                nums[k++] = value;
            }
        }
        return k;
    }
}
