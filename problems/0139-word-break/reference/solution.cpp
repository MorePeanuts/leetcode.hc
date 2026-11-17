#include <algorithm>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool wordBreak(const std::string& s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string_view> words(wordDict.begin(), wordDict.end());
        int longest = 0;
        for (const auto& word : wordDict)
            longest = std::max(longest, static_cast<int>(word.size()));
        std::string_view source(s);
        int n = static_cast<int>(s.size());
        std::vector<bool> possible(n + 1);
        possible[0] = true;
        for (int end = 1; end <= n; end++) {
            for (int start = std::max(0, end - longest); start < end; start++) {
                if (possible[start] && words.count(source.substr(start, end - start))) {
                    possible[end] = true;
                    break;
                }
            }
        }
        return possible[n];
    }
};
