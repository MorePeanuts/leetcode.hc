#include <string>

class Solution {
public:
    std::string minWindow(const std::string& s, const std::string& t) {
        int length = static_cast<int>(s.size());
        int missing = static_cast<int>(t.size());
        int need[256] = {0};
        for (int i = 0; i < missing; i++) need[static_cast<unsigned char>(t[i])]++;
        int left = 0;
        int bestStart = 0;
        int bestLength = length + 1;
        for (int right = 0; right < length; right++) {
            if (need[static_cast<unsigned char>(s[right])]-- > 0) missing--;
            if (missing == 0) {
                while (need[static_cast<unsigned char>(s[left])] < 0) {
                    need[static_cast<unsigned char>(s[left])]++;
                    left++;
                }
                int windowLength = right - left + 1;
                if (windowLength < bestLength) {
                    bestLength = windowLength;
                    bestStart = left;
                }
                need[static_cast<unsigned char>(s[left])]++;
                missing++;
                left++;
            }
        }
        return bestLength <= length ? s.substr(bestStart, bestLength) : "";
    }
};
