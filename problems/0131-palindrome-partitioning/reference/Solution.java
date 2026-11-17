import java.util.ArrayList;
import java.util.List;

class Solution {
    private void visit(String s, boolean[][] palindrome, int start,
                       List<String> path, List<List<String>> answer) {
        if (start == s.length()) {
            answer.add(new ArrayList<>(path));
            return;
        }
        for (int end = start; end < s.length(); end++) {
            if (palindrome[start][end]) {
                path.add(s.substring(start, end + 1));
                visit(s, palindrome, end + 1, path, answer);
                path.remove(path.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        int n = s.length();
        boolean[][] palindrome = new boolean[n][n];
        for (int left = n - 1; left >= 0; left--) {
            for (int right = left; right < n; right++) {
                palindrome[left][right] = s.charAt(left) == s.charAt(right) &&
                    (right - left < 2 || palindrome[left + 1][right - 1]);
            }
        }
        List<List<String>> answer = new ArrayList<>();
        visit(s, palindrome, 0, new ArrayList<>(), answer);
        return answer;
    }
}
