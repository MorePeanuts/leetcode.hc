class Solution {
    public int findKthLargest(int[] nums, int k) {
        int[] counts = new int[20001];
        for (int value : nums) counts[value + 10000]++;
        for (int value = 20000; value >= 0; value--) {
            k -= counts[value];
            if (k <= 0) return value - 10000;
        }
        return 0;
    }
}
