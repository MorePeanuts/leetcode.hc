class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int n = piles.size();
        long long total = 0;
        int high = 0;
        for (int i = 0; i < n; i++) {
            total += piles[i];
            if (piles[i] > high) {
                high = piles[i];
            }
        }
        int low = (total + h - 1) / h;
        while (low < high) {
            int speed = low + (high - low) / 2;
            long long hours = 0;
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
};
