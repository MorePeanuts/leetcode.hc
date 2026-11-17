class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split(" +");
        StringBuilder result = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            if (i < words.length - 1) result.append(' ');
            result.append(words[i]);
        }
        return result.toString();
    }
}
