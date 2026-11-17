class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();
        int[] ways = new int[n + 1];
        ways[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = n; j > 0; j--) {
                if (s.charAt(i) == t.charAt(j - 1)) {
                    ways[j] = ways[j] > Integer.MAX_VALUE - ways[j - 1]
                            ? Integer.MAX_VALUE : ways[j] + ways[j - 1];
                }
            }
        }
        return ways[n];
    }
}
