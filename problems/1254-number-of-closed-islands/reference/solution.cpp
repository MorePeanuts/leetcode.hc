class Solution {
public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        const int dr[] = {1, -1, 0, 0};
        const int dc[] = {0, 0, 1, -1};
        std::vector<int> stack(rows * cols);
        int islands = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] != 0) {
                    continue;
                }
                int size = 0;
                stack[size++] = r * cols + c;
                grid[r][c] = 1;
                bool closed = true;
                while (size > 0) {
                    int id = stack[--size];
                    int row = id / cols;
                    int col = id % cols;
                    if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
                        closed = false;
                    }
                    for (int d = 0; d < 4; ++d) {
                        int nr = row + dr[d];
                        int nc = col + dc[d];
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 0) {
                            grid[nr][nc] = 1;
                            stack[size++] = nr * cols + nc;
                        }
                    }
                }
                if (closed) {
                    ++islands;
                }
            }
        }
        return islands;
    }
};
