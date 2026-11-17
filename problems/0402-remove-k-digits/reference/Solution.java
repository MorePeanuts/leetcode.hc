class Solution {
    public String removeKdigits(String num, int k) {
        char[] digits = new char[num.length()];
        int len = 0;
        int n = num.length();
        for (int i = 0; i < n; ++i) {
            while (k > 0 && len > 0 && digits[len - 1] > num.charAt(i)) {
                --len;
                --k;
            }
            digits[len++] = num.charAt(i);
        }
        len -= k;
        int start = 0;
        while (start < len && digits[start] == '0') {
            ++start;
        }
        return start == len ? "0" : new String(digits, start, len - start);
    }
}
