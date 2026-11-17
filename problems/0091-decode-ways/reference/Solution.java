class Solution {
    public int numDecodings(String s) {
        int twoBack = 1;
        int oneBack = s.charAt(0) == '0' ? 0 : 1;
        int length = s.length();
        for (int i = 1; i < length; i++) {
            int current = s.charAt(i) != '0' ? oneBack : 0;
            if (s.charAt(i - 1) == '1' || (s.charAt(i - 1) == '2' && s.charAt(i) <= '6')) {
                current = current > Integer.MAX_VALUE - twoBack ? Integer.MAX_VALUE : current + twoBack;
            }
            twoBack = oneBack;
            oneBack = current;
        }
        return oneBack;
    }
}
