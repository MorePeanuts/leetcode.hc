class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        using Edge = pair<string, double>;
        unordered_map<string, vector<Edge>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            const auto& a = equations[i][0];
            const auto& b = equations[i][1];
            graph[a].emplace_back(b, values[i]);
            graph[b].emplace_back(a, 1.0 / values[i]);
        }
        auto quotient = [&](const string& start, const string& target) {
            if (!graph.count(start) || !graph.count(target)) {
                return -1.0;
            }
            unordered_set<string> seen{start};
            queue<Edge> pending;
            pending.emplace(start, 1.0);
            while (!pending.empty()) {
                auto [node, product] = pending.front();
                pending.pop();
                if (node == target) {
                    return product;
                }
                for (const auto& [next, ratio] : graph.at(node)) {
                    if (seen.insert(next).second) {
                        pending.emplace(next, product * ratio);
                    }
                }
            }
            return -1.0;
        };
        vector<double> result;
        for (const auto& q : queries) {
            result.push_back(quotient(q[0], q[1]));
        }
        return result;
    }
};
