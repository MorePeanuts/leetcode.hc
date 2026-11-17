class Solution {
    static void reach(const vector<vector<int>> &heights, int rows, int cols, bool far, vector<char> &seen) {
        vector<int> queue(rows * cols);
        int head = 0;
        int tail = 0;
        int side = far ? cols - 1 : 0;
        int edge = far ? rows - 1 : 0;
        for (int r = 0; r < rows; r++) {
            int index = r * cols + side;
            seen[index] = true;
            queue[tail++] = index;
        }
        for (int c = 0; c < cols; c++) {
            int index = edge * cols + c;
            if (!seen[index]) {
                seen[index] = true;
                queue[tail++] = index;
            }
        }
        const int dy[] = {-1, 1, 0, 0};
        const int dx[] = {0, 0, -1, 1};
        while (head < tail) {
            int index = queue[head++];
            int row = index / cols;
            int col = index % cols;
            for (int d = 0; d < 4; d++) {
                int r = row + dy[d];
                int c = col + dx[d];
                if (r < 0 || r >= rows || c < 0 || c >= cols) {
                    continue;
                }
                int next = r * cols + c;
                if (!seen[next] && heights[r][c] >= heights[row][col]) {
                    seen[next] = true;
                    queue[tail++] = next;
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int total = rows * cols;
        vector<char> pacific(total), atlantic(total);
        reach(heights, rows, cols, false, pacific);
        reach(heights, rows, cols, true, atlantic);
        vector<vector<int>> result;
        for (int i = 0; i < total; i++) {
            if (pacific[i] && atlantic[i]) {
                result.push_back({i / cols, i % cols});
            }
        }
        return result;
    }
};
