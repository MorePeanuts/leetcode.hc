class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        const int dr[] = {1, -1, 0, 0};
        const int dc[] = {0, 0, 1, -1};
        std::vector<int> queue(rows * cols);
        std::vector<int> degree(rows * cols);
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
};
