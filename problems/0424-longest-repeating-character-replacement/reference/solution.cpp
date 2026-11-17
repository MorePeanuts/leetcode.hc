class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26);
        int most = 0;
        int left = 0;
        int n = static_cast<int>(s.size());
        for (int right = 0; right < n; ++right) {
            int frequency = ++count[(s[right]) - ('A')];
            if (frequency > most) {
                most = frequency;
            }
            if (right - left + 1 - most > k) {
                --count[(s[left]) - ('A')];
                ++left;
            }
        }
        return n - left;
    }
};
