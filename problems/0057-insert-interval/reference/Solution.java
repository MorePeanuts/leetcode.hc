class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        java.util.List<int[]> result = new java.util.ArrayList<>(n + 1);
        int low = newInterval[0];
        int high = newInterval[1];
        int i = 0;
        while (i < n && intervals[i][1] < low) {
            result.add(intervals[i++]);
        }
        while (i < n && intervals[i][0] <= high) {
            if (intervals[i][0] < low) {
                low = intervals[i][0];
            }
            if (intervals[i][1] > high) {
                high = intervals[i][1];
            }
            i++;
        }
        result.add(new int[]{low, high});
        while (i < n) {
            result.add(intervals[i++]);
        }
        return result.toArray(new int[0][]);
    }
}
