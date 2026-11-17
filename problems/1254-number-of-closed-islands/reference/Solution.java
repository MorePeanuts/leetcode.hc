class Solution {
    public int closedIsland(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};
        int[] stack = new int[rows * cols];
        int islands = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] != 0) {
                    continue;
                }
                int size = 0;
                stack[size++] = r * cols + c;
                grid[r][c] = 1;
                boolean closed = true;
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
}
