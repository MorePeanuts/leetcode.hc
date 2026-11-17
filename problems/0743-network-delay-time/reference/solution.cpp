class Solution {
    using Entry = std::pair<double, int>;
    using Heap = std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>>;

public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        int edges = static_cast<int>(times.size());
        std::vector<int> first(n + 1);
        std::vector<int> next(edges);
        std::vector<int> distance(n + 1);
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
        Heap queue;
        distance[k] = 0;
        queue.emplace(0, k);
        while (static_cast<int>(queue.size()) > 0) {
            Entry entry = queue.top();
            queue.pop();
            int node = entry.second;
            int cost = static_cast<int>(entry.first);
            if (cost != distance[node]) {
                continue;
            }
            for (int edge = first[node]; edge >= 0; edge = next[edge]) {
                int to = times[edge][1];
                int candidate = cost + times[edge][2];
                if (candidate < distance[to]) {
                    distance[to] = candidate;
                    queue.emplace(candidate, to);
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
};
