class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = static_cast<int>(graph.size());
        vector<int> color(n), stack(n);
        for (int start = 0; start < n; start++) {
            if (color[start] != 0) continue;
            color[start] = 1;
            int count = 1;
            stack[0] = start;
            while (count > 0) {
                int node = stack[--count];
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == color[node]) return false;
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        stack[count++] = neighbor;
                    }
                }
            }
        }
        return true;
    }
};
