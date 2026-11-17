class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] last = new int[128];
        int start = 0;
        int best = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            start = Math.max(start, last[ch]);
            last[ch] = i + 1;
            best = Math.max(best, i + 1 - start);
        }
        return best;
    }
}
