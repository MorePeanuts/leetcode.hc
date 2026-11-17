class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int left = 0;
        int right = n - 1;
        for (int i = right; i >= 0; i--) {
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];
            if (a > b) {
                result[i] = a;
                left++;
            } else {
                result[i] = b;
                right--;
            }
        }
        return result;
    }
}
