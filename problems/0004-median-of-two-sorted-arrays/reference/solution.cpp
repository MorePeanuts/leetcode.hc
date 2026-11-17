class Solution {
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
        int m = a.size();
        int n = b.size();
        if (m > n) {
            return findMedianSortedArrays(b, a);
        }
        int left = 0;
        int right = m;
        int half = (m + n + 1) / 2;
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = half - i;
            int aLeft = i == 0 ? INT_MIN : a[i - 1];
            int aRight = i == m ? INT_MAX : a[i];
            int bLeft = j == 0 ? INT_MIN : b[j - 1];
            int bRight = j == n ? INT_MAX : b[j];

            if (aLeft > bRight) {
                right = i - 1;
            } else if (bLeft > aRight) {
                left = i + 1;
            } else {
                int lower = max(aLeft, bLeft);
                if ((m + n) % 2 != 0) {
                    return lower;
                }
                int upper = min(aRight, bRight);
                return ((double)lower + upper) / 2.0;
            }
        }
        return 0;
    }
};
