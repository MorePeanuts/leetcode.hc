#include <climits>
#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(const std::string& s, const std::string& t) {
        int m = static_cast<int>(s.size());
        int n = static_cast<int>(t.size());
        std::vector<int> ways(n + 1);
        ways[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = n; j > 0; j--) {
                if (s[i] == t[j - 1]) {
                    ways[j] = ways[j] > INT_MAX - ways[j - 1] ? INT_MAX : ways[j] + ways[j - 1];
                }
            }
        }
        return ways[n];
    }
};
