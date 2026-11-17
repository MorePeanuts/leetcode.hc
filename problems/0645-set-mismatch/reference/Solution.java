class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        boolean[] seen = new boolean[n + 1];
        int total = 0;
        int duplicate = 0;
        for (int i = 0; i < n; i++) {
            int value = nums[i];
            total += value;
            if (seen[value]) {
                duplicate = value;
            }
            seen[value] = true;
        }
        int missing = n * (n + 1) / 2 - total + duplicate;
        return new int[]{duplicate, missing};
    }
}
