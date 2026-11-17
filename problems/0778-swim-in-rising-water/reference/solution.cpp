class Solution {
    using Entry = std::pair<double, int>;
    using Heap = std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>>;

public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        int n = static_cast<int>(grid.size());
        const int dr[] = {1, -1, 0, 0};
        const int dc[] = {0, 0, 1, -1};
        std::vector<int> best(n * n);
        for (int i = 0; i < n * n; ++i) {
            best[i] = n * n;
        }
        Heap queue;
        best[0] = grid[0][0];
        queue.emplace(best[0], 0);
        int answer = -1;
        while (static_cast<int>(queue.size()) > 0) {
            Entry entry = queue.top();
            queue.pop();
            int node = entry.second;
            int time = static_cast<int>(entry.first);
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
                        queue.emplace(candidate, next);
                    }
                }
            }
        }


        return answer;
    }
};
