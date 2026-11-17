class Solution {
    void visit(const std::vector<std::vector<int>>& graph, int size, std::vector<std::vector<int>>& result, std::vector<int>& path, int node) {
        if (node == size - 1) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < static_cast<int>(graph[node].size()); ++i) {
            int value = graph[node][i];
            path.push_back(value);
            visit(graph, size, result, path, value);
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        int size = static_cast<int>(graph.size());
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        path.push_back(0);
        visit(graph, size, result, path, 0);
        return result;
    }
};
