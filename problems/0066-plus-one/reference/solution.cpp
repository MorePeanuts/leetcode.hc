class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;
        }
        std::vector<int> result;
        result.reserve(digits.size() + 1);
        result.push_back(1);
        result.insert(result.end(), digits.begin(), digits.end());
        return result;
    }
};
