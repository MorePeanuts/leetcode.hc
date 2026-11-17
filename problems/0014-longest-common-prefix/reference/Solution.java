class Solution {
    public String longestCommonPrefix(String[] strs) {
        String first = strs[0];
        for (int i = 0; i < first.length(); i++)
            for (String word : strs)
                if (i == word.length() || word.charAt(i) != first.charAt(i))
                    return first.substring(0, i);
        return first;
    }
}
