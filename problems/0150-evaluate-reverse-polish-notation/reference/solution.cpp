class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::vector<int> stack(static_cast<int>(tokens.size()));
        int size = 0;
        for (int i = 0; i < static_cast<int>(tokens.size()); ++i) {
            int op = tokens[i][0];
            if (tokens[i].size() == 1 && (op == ('+') || op == ('-') || op == ('*') || op == ('/'))) {
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
                stack[size++] = std::stoi(tokens[i]);
            }
        }
        int answer = stack[0];
        return answer;
    }
};
