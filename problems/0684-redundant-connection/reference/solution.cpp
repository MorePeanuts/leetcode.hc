#include <numeric>
#include <vector>

class Solution {
    static int find(std::vector<int>& parent, int node) {
        while (parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        std::vector<int> parent(edges.size() + 1), size(edges.size() + 1, 1);
        std::iota(parent.begin(), parent.end(), 0);
        for (const auto& edge : edges) {
            int a = find(parent, edge[0]);
            int b = find(parent, edge[1]);
            if (a == b) return edge;
            if (size[a] < size[b]) std::swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
        return {};
    }
};
