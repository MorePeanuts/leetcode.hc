class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        string stack(n, '\0');

        int size = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
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
};
