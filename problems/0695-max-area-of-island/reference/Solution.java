class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[] queue = new int[rows * cols];
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        int best = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    continue;
                }
                int tail = 1;
                queue[0] = r * cols + c;
                grid[r][c] = 0;
                for (int head = 0; head < tail; head++) {
                    int position = queue[head];
                    int x = position / cols;
                    int y = position % cols;
                    for (int d = 0; d < 4; d++) {
                        int i = x + dx[d];
                        int j = y + dy[d];
                        if (i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] == 1) {
                            grid[i][j] = 0;
                            queue[tail++] = i * cols + j;
                        }
                    }
                }
                if (tail > best) {
                    best = tail;
                }
            }
        }
        return best;
    }
}
