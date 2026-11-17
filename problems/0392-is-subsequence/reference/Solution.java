class Solution {
    public boolean isSubsequence(String s, String t) {
        int matched = 0;
        for (int i = 0; matched < s.length() && i < t.length(); ++i) {
            if (s.charAt(matched) == t.charAt(i)) {
                ++matched;
            }
        }
        return matched == s.length();
    }
}
