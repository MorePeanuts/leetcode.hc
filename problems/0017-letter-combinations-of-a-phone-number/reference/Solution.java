import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> letterCombinations(String digits) {
        String[] keypad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> result = List.of("");
        for (int i = 0; i < digits.length(); ++i) {
            List<String> next = new ArrayList<>();
            for (String prefix : result) {
                for (char letter : keypad[digits.charAt(i) - '2'].toCharArray()) {
                    next.add(prefix + letter);
                }
            }
            result = next;
        }
        return result;
    }
}
