class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = static_cast<int>(rooms.size());
        vector<int> color(n), stack(n);
        color[0] = 1;
        stack[0] = 0;
        int count = 1;
        int visited = 1;
        while (count > 0) {
            int node = stack[--count];
            for (int neighbor : rooms[node]) {
                if (color[neighbor] == 0) {
                    color[neighbor] = 1;
                    stack[count++] = neighbor;
                    visited++;
                }
            }
        }
        return visited == n;
    }
};
