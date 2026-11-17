import java.util.Arrays;
import java.util.Comparator;

class Solution {
    private int distance(int[] point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    public int[][] kClosest(int[][] points, int k) {
        Arrays.sort(points, Comparator.comparingInt(this::distance));
        return Arrays.copyOf(points, k);
    }
}
