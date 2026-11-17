import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    private record Entry(double priority, int value) {}

    public int networkDelayTime(int[][] times, int n, int k) {
        int edges = times.length;
        int[] first = new int[n + 1];
        int[] next = new int[edges];
        int[] distance = new int[n + 1];
        int unreachable = 1000000000;
        for (int i = 1; i <= n; ++i) {
            first[i] = -1;
            distance[i] = unreachable;
        }
        for (int i = 0; i < edges; ++i) {
            int from = times[i][0];
            next[i] = first[from];
            first[from] = i;
        }
        PriorityQueue<Entry> queue = new PriorityQueue<>(Comparator.comparingDouble(Entry::priority));
        distance[k] = 0;
        queue.add(new Entry(0, k));
        while (queue.size() > 0) {
            Entry entry = queue.remove();
            int node = entry.value();
            int cost = (int)entry.priority();
            if (cost != distance[node]) {
                continue;
            }
            for (int edge = first[node]; edge >= 0; edge = next[edge]) {
                int to = times[edge][1];
                int candidate = cost + times[edge][2];
                if (candidate < distance[to]) {
                    distance[to] = candidate;
                    queue.add(new Entry(candidate, to));
                }
            }
        }
        int answer = 0;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] > answer) {
                answer = distance[i];
            }
        }




        return answer == unreachable ? -1 : answer;
    }
}
