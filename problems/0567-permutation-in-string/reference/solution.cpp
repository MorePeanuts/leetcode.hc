class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) {
            return false;
        }
        int diff[26] = {};
        for (int i = 0; i < m; i++) {
            diff[s1[i] - 'a']--;
            diff[s2[i] - 'a']++;
        }
        int nonzero = 0;
        for (int i = 0; i < 26; i++) {
            if (diff[i] != 0) {
                nonzero++;
            }
        }
        if (nonzero == 0) {
            return true;
        }
        for (int i = m; i < n; i++) {
            int entering = s2[i] - 'a';
            int leaving = s2[i - m] - 'a';
            if (entering == leaving) {
                continue;
            }
            if (diff[entering] == 0) {
                nonzero++;
            }
            diff[entering]++;
            if (diff[entering] == 0) {
                nonzero--;
            }
            if (diff[leaving] == 0) {
                nonzero++;
            }
            diff[leaving]--;
            if (diff[leaving] == 0) {
                nonzero--;
            }
            if (nonzero == 0) {
                return true;
            }
        }
        return false;
    }
};
