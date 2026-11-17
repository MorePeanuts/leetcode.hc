class Solution {
    public double findMedianSortedArrays(int[] a, int[] b) {
        int m = a.length;
        int n = b.length;
        if (m > n) {
            return findMedianSortedArrays(b, a);
        }
        int left = 0;
        int right = m;
        int half = (m + n + 1) / 2;
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = half - i;
            int aLeft = i == 0 ? Integer.MIN_VALUE : a[i - 1];
            int aRight = i == m ? Integer.MAX_VALUE : a[i];
            int bLeft = j == 0 ? Integer.MIN_VALUE : b[j - 1];
            int bRight = j == n ? Integer.MAX_VALUE : b[j];

            if (aLeft > bRight) {
                right = i - 1;
            } else if (bLeft > aRight) {
                left = i + 1;
            } else {
                int lower = Math.max(aLeft, bLeft);
                if ((m + n) % 2 != 0) {
                    return lower;
                }
                int upper = Math.min(aRight, bRight);
                return ((double)lower + upper) / 2.0;
            }
        }
        return 0;
    }
}
