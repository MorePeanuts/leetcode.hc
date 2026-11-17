class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::string digits(num.size(), '0');
        int len = 0;
        int n = static_cast<int>(num.size());
        for (int i = 0; i < n; ++i) {
            while (k > 0 && len > 0 && digits[len - 1] > num[i]) {
                --len;
                --k;
            }
            digits[len++] = num[i];
        }
        len -= k;
        int start = 0;
        while (start < len && digits[start] == '0') {
            ++start;
        }
        return start == len ? "0" : digits.substr(start, len - start);
    }
};
