class Solution {
    public int evalRPN(String[] tokens) {
        int[] stack = new int[tokens.length];
        int size = 0;
        for (int i = 0; i < tokens.length; ++i) {
            int op = tokens[i].charAt(0);
            if (tokens[i].length() == 1 && (op == ('+') || op == ('-') || op == ('*') || op == ('/'))) {
                int right = stack[--size];
                int left = stack[--size];
                if (op == ('+')) {
                    stack[size++] = left + right;
                } else if (op == ('-')) {
                    stack[size++] = left - right;
                } else if (op == ('*')) {
                    stack[size++] = left * right;
                } else {
                    stack[size++] = left / right;
                }
            } else {
                stack[size++] = Integer.parseInt(tokens[i]);
            }
        }
        int answer = stack[0];
        return answer;
    }
}
