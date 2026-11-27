class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestRange(s, 0, s.size(), k);
    }

    private:
    static int longestRange(const string& s, int begin, int end, int k) {
        if (end - begin < k) return 0;
        int counts[26] = {0};
        for (int i = begin; i < end; i++) {
            counts[s[i] - 'a']++;
        }
        int start = begin, best = 0;
        for (int i = begin; i < end; i++) {
            if (counts[s[i] - 'a'] < k) {
                if (i - start >= k) {
                    int length = longestRange(s, start, i, k);
                    if (length > best) best = length;
                }
                start = i + 1;
            }
        }
        if (start == begin) return end - begin;
        int tail = longestRange(s, start, end, k);
        return tail > best ? tail : best;
    }
};
