import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (words.length != pattern.length()) {
            return false;
        }
        Map<Character, String> forward = new HashMap<>();
        Map<String, Character> reverse = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            char letter = pattern.charAt(i);
            String word = words[i];
            String previousWord = forward.putIfAbsent(letter, word);
            Character previousLetter = reverse.putIfAbsent(word, letter);
            if ((previousWord != null && !previousWord.equals(word)) ||
                (previousLetter != null && previousLetter != letter)) {
                return false;
            }
        }
        return true;
    }
}
