class Solution {
    public int change(int amount, int[] coins) {
        int[] ways = new int[amount + 1];
        ways[0] = 1;
        for (int i = 0; i < coins.length; i++) {
            int coin = coins[i];
            for (int total = coin; total <= amount; total++) {
                ways[total] = ways[total] > Integer.MAX_VALUE - ways[total - coin]
                        ? Integer.MAX_VALUE : ways[total] + ways[total - coin];
            }
        }
        return ways[amount];
    }
}
