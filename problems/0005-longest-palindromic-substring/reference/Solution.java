class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int start = 0;
        int length = 1;
        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center >> 1;
            int right = (center + 1) >> 1;
            while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
                --left;
                ++right;
            }
            if (right - left - 1 > length) {
                start = left + 1;
                length = right - left - 1;
            }
        }
        return s.substring(start, start + length);
    }
}
