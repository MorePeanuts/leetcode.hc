class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        int edgeCount = static_cast<int>(edges.size());
        std::vector<int> first(n);
        std::vector<int> neighbor(2 * edgeCount);
        std::vector<int> next(2 * edgeCount);
        std::vector<int> degree(n);
        std::vector<int> queue(n);
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
        return std::vector<int>(queue.begin() + head, queue.begin() + tail);
    }
};
