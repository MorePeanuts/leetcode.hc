import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        int edgeCount = edges.length;
        int[] first = new int[n];
        int[] neighbor = new int[2 * edgeCount];
        int[] next = new int[2 * edgeCount];
        int[] degree = new int[n];
        int[] queue = new int[n];
        for (int node = 0; node < n; ++node) {
            first[node] = -1;
        }
        for (int edge = 0; edge < edgeCount; ++edge) {
            for (int direction = 0; direction < 2; ++direction) {
                int from = edges[edge][direction];
                int slot = 2 * edge + direction;
                neighbor[slot] = edges[edge][1 - direction];
                next[slot] = first[from];
                first[from] = slot;
                ++degree[from];
            }
        }

        int head = 0;
        int tail = 0;
        for (int node = 0; node < n; ++node) {
            if (degree[node] <= 1) {
                queue[tail++] = node;
            }
        }
        int remaining = n;
        while (remaining > 2) {
            int layerEnd = tail;
            remaining -= layerEnd - head;
            while (head < layerEnd) {
                int leaf = queue[head++];
                for (int edge = first[leaf]; edge >= 0; edge = next[edge]) {
                    int adjacent = neighbor[edge];
                    if (--degree[adjacent] == 1) {
                        queue[tail++] = adjacent;
                    }
                }
            }
        }
        List<Integer> result = new ArrayList<>(tail - head);
        for (int i = head; i < tail; ++i) {
            result.add(queue[i]);
        }
        return result;
    }
}
