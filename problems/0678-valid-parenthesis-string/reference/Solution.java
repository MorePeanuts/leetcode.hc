class Solution {
    public boolean checkValidString(String s) {
        int minimum = 0;
        int maximum = 0;
        for (int i = 0; i < s.length(); ++i) {
            minimum += s.charAt(i) == '(' ? 1 : -1;
            maximum += s.charAt(i) == ')' ? -1 : 1;
            if (maximum < 0) {
                return false;
            }
            if (minimum < 0) {
                minimum = 0;
            }
        }
        return minimum == 0;
    }
}
