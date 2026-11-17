class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        result[0] = 0;
        for (int value = 1; value <= n; value++) {
            result[value] = result[value >> 1] + (value & 1);
        }
        return result;
    }
};
