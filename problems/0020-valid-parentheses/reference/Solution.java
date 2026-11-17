class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        char[] stack = new char[n];

        int size = 0;
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            switch (c) {
                case '(':
                    stack[size++] = ')';
                    break;
                case '[':
                    stack[size++] = ']';
                    break;
                case '{':
                    stack[size++] = '}';
                    break;
                default:
                    if (size == 0 || stack[--size] != c) {
                        return false;
                    }
            }
        }
        return size == 0;
    }
}
