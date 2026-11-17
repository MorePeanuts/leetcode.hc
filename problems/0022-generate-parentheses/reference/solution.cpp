#include <string>
#include <vector>

class Solution {
    static void generate(int n, int opened, int closed, std::string& path,
                         std::vector<std::string>& result) {
        if (closed == n) {
            result.push_back(path);
            return;
        }
        int index = opened + closed;
        if (opened < n) {
            path[index] = '(';
            generate(n, opened + 1, closed, path, result);
        }
        if (closed < opened) {
            path[index] = ')';
            generate(n, opened, closed + 1, path, result);
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string path(2 * n, ' ');
        generate(n, 0, 0, path, result);
        return result;
    }
};
