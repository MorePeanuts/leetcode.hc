class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = static_cast<int>(s.size());
        int start = 0;
        int length = 1;
        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center >> 1;
            int right = (center + 1) >> 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            if (right - left - 1 > length) {
                start = left + 1;
                length = right - left - 1;
            }
        }
        return s.substr(start, length);
    }
};
