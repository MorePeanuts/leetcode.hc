class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const vector<vector<int>> neighbors{{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
        string start;
        for (const auto& row : board) {
            for (int tile : row) start.push_back('0' + tile);
        }
        unordered_set<string> seen{start};
        queue<string> pending;
        pending.push(start);
        for (int moves = 0; !pending.empty(); moves++) {
            for (int count = pending.size(); count > 0; count--) {
                string state = pending.front();
                pending.pop();
                if (state == "123450") return moves;
                int blank = state.find('0');
                for (int to : neighbors[blank]) {
                    string next = state;
                    swap(next[blank], next[to]);
                    if (seen.insert(next).second) pending.push(next);
                }
            }
        }
        return -1;
    }
};
