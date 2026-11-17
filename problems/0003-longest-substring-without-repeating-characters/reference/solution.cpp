#include <array>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::array<int, 256> last{};
        int start = 0;
        int best = 0;
        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            unsigned char ch = static_cast<unsigned char>(s[i]);
            if (last[ch] > start) start = last[ch];
            last[ch] = i + 1;
            if (i + 1 - start > best) best = i + 1 - start;
        }
        return best;
    }
};
