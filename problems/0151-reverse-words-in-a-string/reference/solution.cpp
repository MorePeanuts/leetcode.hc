#include <string>

class Solution {
public:
    std::string reverseWords(const std::string& s) {
        std::string result;
        size_t end = s.size();
        while (end > 0) {
            while (end > 0 && s[end - 1] == ' ') end--;
            if (end == 0) break;
            size_t start = end;
            while (start > 0 && s[start - 1] != ' ') start--;
            if (!result.empty()) result += ' ';
            result.append(s, start, end - start);
            end = start;
        }
        return result;
    }
};
