import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    private record Entry(double priority, int value) {}

    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};
        int[] best = new int[n * n];
        for (int i = 0; i < n * n; ++i) {
            best[i] = n * n;
        }
        PriorityQueue<Entry> queue = new PriorityQueue<>(Comparator.comparingDouble(Entry::priority));
        best[0] = grid[0][0];
        queue.add(new Entry(best[0], 0));
        int answer = -1;
        while (queue.size() > 0) {
            Entry entry = queue.remove();
            int node = entry.value();
            int time = (int)entry.priority();
            if (time != best[node]) {
                continue;
            }
            if (node == n * n - 1) {
                answer = time;
                break;
            }
            int row = node / n;
            int col = node % n;
            for (int d = 0; d < 4; ++d) {
                int nr = row + dr[d];
                int nc = col + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int next = nr * n + nc;
                    int candidate = time > grid[nr][nc] ? time : grid[nr][nc];
                    if (candidate < best[next]) {
                        best[next] = candidate;
                        queue.add(new Entry(candidate, next));
                    }
                }
            }
        }


        return answer;
    }
}
