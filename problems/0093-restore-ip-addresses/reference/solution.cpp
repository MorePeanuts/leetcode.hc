class Solution {
    void visit(const std::string& s, int start, int count, const std::string& path, std::vector<std::string>& result) {
        int left = 4 - count;
        if (static_cast<int>(s.size()) - start < left || static_cast<int>(s.size()) - start > 3 * left) {
            return;
        }
        if (left == 0) {
            result.push_back(path);
            return;
        }
        int value = 0;
        for (int length = 1; length <= 3 && start + length <= static_cast<int>(s.size()); ++length) {
            value = value * 10 + s[start + length - 1] - '0';
            if (value > 255 || (length > 1 && s[start] == '0')) {
                break;
            }
            std::string next = path + (count == 0 ? "" : ".") + s.substr(start, length);
            visit(s, start + length, count + 1, next, result);
        }
    }

public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        visit(s, 0, 0, "", result);
        return result;
    }
};
