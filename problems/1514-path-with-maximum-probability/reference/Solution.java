import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    private record Entry(double priority, int value) {}

    public double maxProbability(int n, int[][] edges, double[] succProb, int startNode, int endNode) {
        int m = edges.length;
        int[] first = new int[n];
        int[] next = new int[2 * m];
        int[] to = new int[2 * m];
        double[] best = new double[n];
        for (int node = 0; node < n; ++node) {
            first[node] = -1;
        }
        for (int i = 0; i < m; ++i) {
            for (int dir = 0; dir < 2; ++dir) {
                int from = edges[i][dir];
                int edge = 2 * i + dir;
                to[edge] = edges[i][1 - dir];
                next[edge] = first[from];
                first[from] = edge;
            }
        }
        PriorityQueue<Entry> queue = new PriorityQueue<>(Comparator.comparingDouble(Entry::priority));
        best[startNode] = 1;
        queue.add(new Entry(-1, startNode));
        while (queue.size() > 0) {
            Entry entry = queue.remove();
            int node = entry.value();
            double probability = -entry.priority();
            if (probability < best[node]) {
                continue;
            }
            if (node == endNode) {
                break;
            }
            for (int edge = first[node]; edge >= 0; edge = next[edge]) {
                double candidate = probability * succProb[edge / 2];
                int neighbor = to[edge];
                if (candidate > best[neighbor]) {
                    best[neighbor] = candidate;
                    queue.add(new Entry(-candidate, neighbor));
                }
            }
        }
        double answer = best[endNode];





        return answer;
    }
}
