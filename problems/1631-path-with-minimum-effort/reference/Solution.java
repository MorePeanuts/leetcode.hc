import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    private record Entry(int position, int cost) {}

    public int minimumEffortPath(int[][] heights) {
        int rows = heights.length;
        int cols = heights[0].length;
        int total = rows * cols;
        int[] best = new int[total];
        Arrays.fill(best, Integer.MAX_VALUE);
        PriorityQueue<Entry> queue = new PriorityQueue<>(Comparator.comparingInt(Entry::cost));
        best[0] = 0;
        queue.add(new Entry(0, 0));
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        while (!queue.isEmpty()) {
            Entry entry = queue.remove();
            int position = entry.position();
            int cost = entry.cost();
            if (cost != best[position]) {
                continue;
            }
            if (position == total - 1) {

                return cost;
            }
            int r = position / cols;
            int c = position % cols;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                    continue;
                }
                int next = nr * cols + nc;
                int difference = Math.abs(heights[r][c] - heights[nr][nc]);
                int candidate = cost > difference ? cost : difference;
                if (candidate < best[next]) {
                    best[next] = candidate;
                    queue.add(new Entry(next, candidate));
                }
            }
        }

        return 0;
    }
}
