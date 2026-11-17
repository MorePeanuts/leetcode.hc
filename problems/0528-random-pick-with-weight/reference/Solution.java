import java.util.Random;

class Solution {
    private final int[] prefix;
    private final Random random = new Random();

    public Solution(int[] w) {
        prefix = new int[w.length];
        int total = 0;
        for (int i = 0; i < w.length; i++) {
            total += w[i];
            prefix[i] = total;
        }
    }

    public int pickIndex() {
        int target = random.nextInt(prefix[prefix.length - 1]);
        int lo = 0, hi = prefix.length - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (prefix[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
