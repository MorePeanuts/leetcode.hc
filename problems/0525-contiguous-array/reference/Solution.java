class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        int[] first = new int[2 * n + 1];
        // Store index plus one, reserving zero for balances not yet seen.
        int balance = n;
        first[balance] = -1;
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            balance += nums[i] == 1 ? 1 : -1;
            if (first[balance] != 0) {
                int previous = first[balance] < 0 ? -1 : first[balance] - 1;
                int size = i - previous;
                if (size > answer) {
                    answer = size;
                }
            } else {
                first[balance] = i + 1;
            }
        }
        return answer;
    }
}
