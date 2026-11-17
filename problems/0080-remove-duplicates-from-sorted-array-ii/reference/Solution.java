class Solution {
    public int removeDuplicates(int[] nums) {
        int length = 0;
        for (int i = 0; i < nums.length; i++) {
            int value = nums[i];
            if (length < 2 || value != nums[length - 2]) {
                nums[length] = value;
                length++;
            }
        }
        return length;
    }
}
