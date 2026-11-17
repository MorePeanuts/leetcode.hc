class Solution {
    public int countSubstrings(String s) {
        int count = 0;
        int n = s.length();
        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center >> 1;
            int right = (center + 1) >> 1;
            while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
                ++count;
                --left;
                ++right;
            }
        }
        return count;
    }
}
