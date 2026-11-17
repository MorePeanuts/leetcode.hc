class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int total = 0;
        for (int i = 0; i < nums.length; ++i) {
            total += nums[i];
        }
        if (target > total || target < -total || ((total + target) & 1) != 0) {
            return 0;
        }
        int goal = (total + target) >> 1;
        int[] ways = new int[goal + 1];
        ways[0] = 1;
        for (int i = 0; i < nums.length; ++i) {
            int value = nums[i];
            for (int subtotal = goal; subtotal >= value; --subtotal) {
                ways[subtotal] += ways[subtotal - value];
            }
        }
        int answer = ways[goal];
        return answer;
    }
}
