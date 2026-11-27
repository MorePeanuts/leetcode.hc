class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; i++) {
            long long radius = bombs[i][2];
            for (int j = 0; j < n; j++) {
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                if (i != j && dx * dx + dy * dy <= radius * radius) {
                    edges[i].push_back(j);
                }
            }
        }
        int best = 0;
        for (int start = 0; start < n; start++) {
            vector<bool> seen(n, false);
            vector<int> queue{start};
            seen[start] = true;
            for (size_t head = 0; head < queue.size(); head++) {
                for (int next : edges[queue[head]]) {
                    if (!seen[next]) {
                        seen[next] = true;
                        queue.push_back(next);
                    }
                }
            }
            best = max(best, static_cast<int>(queue.size()));
            if (best == n) break;
        }
        return best;
    }
};
