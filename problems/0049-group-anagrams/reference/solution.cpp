#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, size_t> indices;
        std::vector<std::vector<std::string>> result;
        for (const auto& word : strs) {
            auto key = word;
            std::sort(key.begin(), key.end());
            auto [entry, added] = indices.try_emplace(key, result.size());
            if (added) result.emplace_back();
            result[entry->second].push_back(word);
        }
        return result;
    }
};
