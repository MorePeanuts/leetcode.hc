class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int last[26] = {};
        vector<int> result;
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++) {
            int latest = last[s[i] - 'a'];
            if (latest > end) {
                end = latest;
            }
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
