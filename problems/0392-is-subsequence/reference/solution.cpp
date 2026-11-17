class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int matched = 0;
        for (int i = 0; matched < static_cast<int>(s.size()) && i < static_cast<int>(t.size()); ++i) {
            if (s[matched] == t[i]) {
                ++matched;
            }
        }
        return matched == static_cast<int>(s.size());
    }
};
