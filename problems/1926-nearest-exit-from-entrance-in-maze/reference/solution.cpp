class Solution {
public:
    int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance) {
        int rows = static_cast<int>(maze.size());
        int cols = static_cast<int>(maze[0].size());
        const int dr[] = {1, -1, 0, 0};
        const int dc[] = {0, 0, 1, -1};
        std::vector<int> queue(rows * cols);
        int head = 0;
        int tail = 0;
        int start = entrance[0] * cols + entrance[1];
        queue[tail++] = start;
        maze[entrance[0]][entrance[1]] = '+';
        int distance = 0;
        int answer = -1;
        while (head < tail && answer < 0) {
            int layerEnd = tail;
            while (head < layerEnd) {
                int id = queue[head++];
                int row = id / cols;
                int col = id % cols;
                if (id != start && (row == 0 || row == rows - 1 || col == 0 || col == cols - 1)) {
                    answer = distance;
                    break;
                }
                for (int d = 0; d < 4; ++d) {
                    int nr = row + dr[d];
                    int nc = col + dc[d];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] == '.') {
                        maze[nr][nc] = '+';
                        queue[tail++] = nr * cols + nc;
                    }
                }
            }
            ++distance;
        }
        return answer;
    }
};
