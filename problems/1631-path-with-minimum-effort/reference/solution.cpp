class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int total = rows * cols;
        vector<int> best(total, INT_MAX);
        using Entry = pair<int, int>;
        priority_queue<Entry, vector<Entry>, greater<Entry>> queue;
        best[0] = 0;
        queue.emplace(0, 0);
        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};
        while (!queue.empty()) {
            auto [cost, position] = queue.top();
            queue.pop();
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
                int difference = abs(heights[r][c] - heights[nr][nc]);
                int candidate = cost > difference ? cost : difference;
                if (candidate < best[next]) {
                    best[next] = candidate;
                    queue.emplace(candidate, next);
                }
            }
        }

        return 0;
    }
};
