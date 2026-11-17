#include <string>
#include <vector>

class Solution {
    static int find(int* parent, int node) {
        while (parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

public:
    bool equationsPossible(vector<string>& equations) {
        int parent[26], size[26];
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i < static_cast<int>(equations.size()); i++) {
            if (equations[i][1] == '=') {
                int a = find(parent, equations[i][0] - 'a');
                int b = find(parent, equations[i][3] - 'a');
                if (a == b) continue;
                if (size[a] < size[b]) {
                    int temporary = a;
                    a = b;
                    b = temporary;
                }
                parent[b] = a;
                size[a] += size[b];
            }
        }
        for (int i = 0; i < static_cast<int>(equations.size()); i++) {
            if (equations[i][1] == '!' && find(parent, equations[i][0] - 'a') == find(parent, equations[i][3] - 'a')) return false;
        }
        return true;
    }
};
