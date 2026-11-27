class Solution {
    public int longestSubstring(String s, int k) {
        return longestRange(s, 0, s.length(), k);
    }

    private int longestRange(String s, int begin, int end, int k) {
        if (end - begin < k) return 0;
        int[] counts = new int[26];
        for (int i = begin; i < end; i++) {
            counts[s.charAt(i) - 'a']++;
        }
        int start = begin, best = 0;
        for (int i = begin; i < end; i++) {
            if (counts[s.charAt(i) - 'a'] < k) {
                if (i - start >= k) {
                    int length = longestRange(s, start, i, k);
                    if (length > best) best = length;
                }
                start = i + 1;
            }
        }
        if (start == begin) return end - begin;
        int tail = longestRange(s, start, end, k);
        return tail > best ? tail : best;
    }
}
