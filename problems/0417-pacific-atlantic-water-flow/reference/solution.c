static void reach(int **heights, int rows, int cols, bool far, bool *seen) {
    int queue[rows * cols];
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

int **pacificAtlantic(int **heights, int rows, int *columnSizes, int *returnSize, int **returnColumnSizes) {
    int cols = columnSizes[0];
    int total = rows * cols;
    bool pacific[total], atlantic[total];
    memset(pacific, 0, sizeof(pacific));
    memset(atlantic, 0, sizeof(atlantic));
    reach(heights, rows, cols, false, pacific);
    reach(heights, rows, cols, true, atlantic);

    int **result = malloc(total * sizeof(*result));
    *returnColumnSizes = malloc(total * sizeof(**returnColumnSizes));
    *returnSize = 0;
    for (int i = 0; i < total; i++) {
        if (pacific[i] && atlantic[i]) {
            int *point = malloc(2 * sizeof(*point));
            point[0] = i / cols;
            point[1] = i % cols;
            result[*returnSize] = point;
            (*returnColumnSizes)[(*returnSize)++] = 2;
        }
    }
    return result;
}
