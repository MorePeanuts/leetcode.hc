class Solution {
    public boolean canPartition(int[] nums) {
        int total = 0;
        for (int i = 0; i < nums.length; i++) total += nums[i];
        if (total % 2 != 0) return false;
        int target = total / 2;
        boolean[] possible = new boolean[target + 1];
        possible[0] = true;
        for (int i = 0; i < nums.length; i++) {
            int value = nums[i];
            for (int subtotal = target; subtotal >= value; subtotal--) {
                if (possible[subtotal - value]) possible[subtotal] = true;
            }
        }
        return possible[target];
    }
}
