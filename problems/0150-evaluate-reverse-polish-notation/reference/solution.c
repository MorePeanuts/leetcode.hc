int evalRPN(char** tokens, int tokensSize) {
    int* stack = calloc((size_t)(tokensSize), sizeof(*stack));
    int size = 0;
    for (int i = 0; i < tokensSize; ++i) {
        int op = tokens[i][0];
        if ((tokens[i][1] == 0 ? 1 : 0) == 1 && (op == ('+') || op == ('-') || op == ('*') || op == ('/'))) {
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
            stack[size++] = atoi(tokens[i]);
        }
    }
    int answer = stack[0];
    free(stack);
    return answer;
}
