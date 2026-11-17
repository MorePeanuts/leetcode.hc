import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int n = s.length();
        int m = p.length();
        int[] need = new int[26];
        int[] window = new int[26];
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < m; i++) need[p.charAt(i) - 'a']++;
        for (int right = 0; right < n; right++) {
            window[s.charAt(right) - 'a']++;
            if (right >= m) window[s.charAt(right - m) - 'a']--;
            if (right + 1 >= m && Arrays.equals(window, need)) result.add(right + 1 - m);
        }
        return result;
    }
}
