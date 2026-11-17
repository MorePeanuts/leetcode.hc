class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};
        int[] queue = new int[rows * cols];
        int[] degree = new int[rows * cols];
        int head = 0;
        int tail = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int id = row * cols + col;
                for (int d = 0; d < 4; ++d) {
                    int nr = row + dr[d];
                    int nc = col + dc[d];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[row][col]) {
                        ++degree[id];
                    }
                }
                if (degree[id] == 0) {
                    queue[tail++] = id;
                }
            }
        }
        int length = 0;
        while (head < tail) {
            int layerEnd = tail;
            while (head < layerEnd) {
                int id = queue[head++];
                int row = id / cols;
                int col = id % cols;
                for (int d = 0; d < 4; ++d) {
                    int nr = row + dr[d];
                    int nc = col + dc[d];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] < matrix[row][col]) {
                        int next = nr * cols + nc;
                        if (--degree[next] == 0) {
                            queue[tail++] = next;
                        }
                    }
                }
            }
            ++length;
        }
        return length;
    }
}
