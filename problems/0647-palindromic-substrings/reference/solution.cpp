class Solution {
public:
    int countSubstrings(std::string s) {
        int count = 0;
        int n = static_cast<int>(s.size());
        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center >> 1;
            int right = (center + 1) >> 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                ++count;
                --left;
                ++right;
            }
        }
        return count;
    }
};
