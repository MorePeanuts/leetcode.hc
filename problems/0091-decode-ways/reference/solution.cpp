#include <climits>
#include <string>

class Solution {
public:
    int numDecodings(const std::string& s) {
        int twoBack = 1;
        int oneBack = s[0] == '0' ? 0 : 1;
        int length = static_cast<int>(s.size());
        for (int i = 1; i < length; i++) {
            int current = s[i] != '0' ? oneBack : 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                current = current > INT_MAX - twoBack ? INT_MAX : current + twoBack;
            }
            twoBack = oneBack;
            oneBack = current;
        }
        return oneBack;
    }
};
