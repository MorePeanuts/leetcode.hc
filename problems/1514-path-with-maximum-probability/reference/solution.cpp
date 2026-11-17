class Solution {
    using Entry = std::pair<double, int>;
    using Heap = std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>>;

public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int startNode, int endNode) {
        int m = static_cast<int>(edges.size());
        std::vector<int> first(n);
        std::vector<int> next(2 * m);
        std::vector<int> to(2 * m);
        std::vector<double> best(n);
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
        Heap queue;
        best[startNode] = 1;
        queue.emplace(-1, startNode);
        while (static_cast<int>(queue.size()) > 0) {
            Entry entry = queue.top();
            queue.pop();
            int node = entry.second;
            double probability = -entry.first;
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
                    queue.emplace(-candidate, neighbor);
                }
            }
        }
        double answer = best[endNode];





        return answer;
    }
};
