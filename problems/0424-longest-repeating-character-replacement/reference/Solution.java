class Solution {
    public int characterReplacement(String s, int k) {
        int[] count = new int[26];
        int most = 0;
        int left = 0;
        int n = s.length();
        for (int right = 0; right < n; ++right) {
            int frequency = ++count[(s.charAt(right)) - ('A')];
            if (frequency > most) {
                most = frequency;
            }
            if (right - left + 1 - most > k) {
                --count[(s.charAt(left)) - ('A')];
                ++left;
            }
        }
        return n - left;
    }
}
