class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        const int dr[] = {1, -1, 0, 0};
        const int dc[] = {0, 0, 1, -1};
        std::vector<int> queue(rows * cols);
        int islands = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] != '1') {
                    continue;
                }
                ++islands;
                int head = 0;
                int tail = 0;
                queue[tail++] = r * cols + c;
                grid[r][c] = '0';
                while (head < tail) {
                    int id = queue[head++];
                    int row = id / cols;
                    int col = id % cols;
                    for (int d = 0; d < 4; ++d) {
                        int nr = row + dr[d];
                        int nc = col + dc[d];
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                            grid[nr][nc] = '0';
                            queue[tail++] = nr * cols + nc;
                        }
                    }
                }
            }
        }
        return islands;
    }
};
