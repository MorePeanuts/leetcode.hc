class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> queue(rows * cols);
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        int fresh = 0;
        int head = 0;
        int tail = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    queue[tail++] = r * cols + c;
                } else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }
        int minutes = 0;
        while (head < tail && fresh > 0) {
            int end = tail;
            while (head < end) {
                int position = queue[head++];
                int x = position / cols;
                int y = position % cols;
                for (int d = 0; d < 4; d++) {
                    int i = x + dx[d];
                    int j = y + dy[d];
                    if (i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        fresh--;
                        queue[tail++] = i * cols + j;
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};
