#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    std::string decodeString(const std::string& s) {
        std::vector<std::pair<size_t, int>> stack;
        std::string decoded;
        int repeat = 0;
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                repeat = repeat * 10 + ch - '0';
            } else if (ch == '[') {
                stack.emplace_back(decoded.size(), repeat);
                repeat = 0;
            } else if (ch == ']') {
                auto [start, count] = stack.back();
                stack.pop_back();
                auto part = decoded.substr(start);
                for (int i = 1; i < count; i++) decoded += part;
            } else {
                decoded += ch;
            }
        }
        return decoded;
    }
};
