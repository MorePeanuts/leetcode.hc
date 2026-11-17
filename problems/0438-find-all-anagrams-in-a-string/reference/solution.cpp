#include <array>

class Solution {
public:
    vector<int> findAnagrams(const string& s, const string& p) {
        int n = static_cast<int>(s.size());
        int m = static_cast<int>(p.size());
        std::array<int, 26> need{}, window{};
        vector<int> result;
        for (int i = 0; i < m; i++) need[p[i] - 'a']++;
        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;
            if (right >= m) window[s[right - m] - 'a']--;
            if (right + 1 >= m && window == need) result.push_back(right + 1 - m);
        }
        return result;
    }
};
