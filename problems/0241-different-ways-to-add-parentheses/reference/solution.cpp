#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    using Cache = std::unordered_map<std::string, std::vector<long long>>;

    static const std::vector<long long>& solve(const std::string& text, Cache& memo) {
        auto [entry, added] = memo.try_emplace(text);
        auto& output = entry->second;
        if (!added) return output;
        for (size_t i = 0; i < text.size(); i++) {
            char op = text[i];
            if (op != '+' && op != '-' && op != '*') continue;
            const auto& left = solve(text.substr(0, i), memo);
            const auto& right = solve(text.substr(i + 1), memo);
            for (long long a : left)
                for (long long b : right)
                    output.push_back(op == '+' ? a + b : op == '-' ? a - b : a * b);
        }
        if (output.empty()) output.push_back(std::stoi(text));
        return output;
    }

public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        Cache memo;
        const auto& values = solve(expression, memo);
        return {values.begin(), values.end()};
    }
};
