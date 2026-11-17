class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        const std::string keypad[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> result{""};
        for (char digit : digits) {
            std::vector<std::string> next;
            for (const auto& prefix : result) {
                for (char letter : keypad[digit - '2']) {
                    next.push_back(prefix + letter);
                }
            }
            result = std::move(next);
        }
        return result;
    }
};
