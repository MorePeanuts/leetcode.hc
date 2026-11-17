class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        int m = static_cast<int>(num1.size());
        int n = static_cast<int>(num2.size());
        std::vector<int> digits(m + n);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int place = i + j + 1;
                int total = digits[place] + ((num1[i]) - ('0')) * ((num2[j]) - ('0'));
                digits[place] = total % 10;
                digits[place - 1] += total / 10;
            }
        }
        int start = 0;
        while (start + 1 < m + n && digits[start] == 0) {
            ++start;
        }
        std::string answer;
        answer.reserve(m + n - start);
        for (int i = start; i < m + n; ++i) {
            answer.push_back(static_cast<char>('0' + digits[i]));
        }
        return answer;
    }
};
