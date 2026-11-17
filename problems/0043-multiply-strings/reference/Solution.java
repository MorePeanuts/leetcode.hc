class Solution {
    public String multiply(String num1, String num2) {
        int m = num1.length();
        int n = num2.length();
        int[] digits = new int[m + n];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int place = i + j + 1;
                int total = digits[place] + ((num1.charAt(i)) - ('0')) * ((num2.charAt(j)) - ('0'));
                digits[place] = total % 10;
                digits[place - 1] += total / 10;
            }
        }
        int start = 0;
        while (start + 1 < m + n && digits[start] == 0) {
            ++start;
        }
        StringBuilder answer = new StringBuilder(m + n - start);
        for (int i = start; i < m + n; ++i) {
            answer.append((char)('0' + digits[i]));
        }
        return answer.toString();
    }
}
