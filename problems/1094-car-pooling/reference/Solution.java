class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] difference = new int[1001];
        for (int i = 0; i < trips.length; ++i) {
            difference[trips[i][1]] += trips[i][0];
            difference[trips[i][2]] -= trips[i][0];
        }
        int onboard = 0;
        boolean feasible = true;
        for (int i = 0; i <= 1000; ++i) {
            onboard += difference[i];
            if (onboard > capacity) {
                feasible = false;
                break;
            }
        }
        return feasible;
    }
}
