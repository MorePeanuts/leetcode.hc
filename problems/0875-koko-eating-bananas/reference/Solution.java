class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        long total = 0;
        int high = 0;
        for (int i = 0; i < n; i++) {
            total += piles[i];
            if (piles[i] > high) {
                high = piles[i];
            }
        }
        int low = (int)((total + h - 1) / h);
        while (low < high) {
            int speed = low + (high - low) / 2;
            long hours = 0;
            for (int i = 0; i < n; i++) {
                hours += (piles[i] + speed - 1) / speed;
            }
            if (hours <= h) {
                high = speed;
            } else {
                low = speed + 1;
            }
        }
        return low;
    }
}
