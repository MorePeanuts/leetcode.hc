int shortestPathBinaryMatrix(int **grid, int rows, int *columnSizes) {
    (void)columnSizes;
    if (grid[0][0] != 0 || grid[rows - 1][rows - 1] != 0) {
        return -1;
    }
    int queue[rows * rows];
    queue[0] = 0;
    grid[0][0] = 1;
    int head = 0;
    int tail = 1;
    int distance = 1;
    while (head < tail) {
        int end = tail;
        while (head < end) {
            int position = queue[head++];
            if (position == rows * rows - 1) {
                return distance;
            }
            int r = position / rows;
            int c = position % rows;
            for (int i = r - 1; i <= r + 1; i++) {
                for (int j = c - 1; j <= c + 1; j++) {
                    if (i >= 0 && i < rows && j >= 0 && j < rows && grid[i][j] == 0) {
                        grid[i][j] = 1;
                        queue[tail++] = i * rows + j;
                    }
                }
            }
        }
        distance++;
    }
    return -1;
}
