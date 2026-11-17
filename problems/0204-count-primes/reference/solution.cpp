class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }
        vector<char> composite(n);
        for (int p = 2; p * p < n; p++) {
            if (!composite[p]) {
                for (int q = p * p; q < n; q += p) {
                    composite[q] = true;
                }
            }
        }
        int count = 0;
        for (int p = 2; p < n; p++) {
            if (!composite[p]) {
                count++;
            }
        }
        return count;
    }
};
