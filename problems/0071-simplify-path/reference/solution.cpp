#include <sstream>

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts;
        istringstream input(path);
        string part;
        while (getline(input, part, '/')) {
            if (part == "..") {
                if (!parts.empty()) {
                    parts.pop_back();
                }
            } else if (!part.empty() && part != ".") {
                parts.push_back(part);
            }
        }
        string result;
        for (const auto &item : parts) {
            result += '/';
            result += item;
        }
        return result.empty() ? "/" : result;
    }
};
