import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<>(wordDict);
        int longest = 0;
        for (String word : wordDict) longest = Math.max(longest, word.length());
        boolean[] possible = new boolean[s.length() + 1];
        possible[0] = true;
        for (int end = 1; end <= s.length(); end++) {
            for (int start = Math.max(0, end - longest); start < end; start++) {
                if (possible[start] && words.contains(s.substring(start, end))) {
                    possible[end] = true;
                    break;
                }
            }
        }
        return possible[s.length()];
    }
}
