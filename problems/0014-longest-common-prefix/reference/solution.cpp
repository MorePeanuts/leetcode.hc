#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        const auto& first = strs.front();
        for (size_t i = 0; i < first.size(); i++)
            for (const auto& word : strs)
                if (i == word.size() || word[i] != first[i]) return first.substr(0, i);
        return first;
    }
};
