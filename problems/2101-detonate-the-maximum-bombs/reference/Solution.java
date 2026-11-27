import java.util.ArrayList;
import java.util.List;

class Solution {
    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> neighbors = new ArrayList<>();
            long radius = bombs[i][2];
            for (int j = 0; j < n; j++) {
                long dx = bombs[i][0] - bombs[j][0];
                long dy = bombs[i][1] - bombs[j][1];
                if (i != j && dx * dx + dy * dy <= radius * radius) {
                    neighbors.add(j);
                }
            }
            edges.add(neighbors);
        }
        int best = 0;
        for (int start = 0; start < n; start++) {
            boolean[] seen = new boolean[n];
            int[] queue = new int[n];
            queue[0] = start;
            seen[start] = true;
            int tail = 1;
            for (int head = 0; head < tail; head++) {
                for (int next : edges.get(queue[head])) {
                    if (!seen[next]) {
                        seen[next] = true;
                        queue[tail++] = next;
                    }
                }
            }
            best = Math.max(best, tail);
            if (best == n) break;
        }
        return best;
    }
}
