static int smaller(int a, int b) {
    return a < b ? a : b;
}

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matSize, cols = matColSize[0];
    *returnSize = rows;
    *returnColumnSizes = malloc(rows * sizeof(int));
    memcpy(*returnColumnSizes, matColSize, rows * sizeof(int));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (mat[r][c] == 0) {
                continue;
            }
            int best = rows + cols;
            if (r > 0) {
                best = smaller(best, mat[r - 1][c] + 1);
            }
            if (c > 0) {
                best = smaller(best, mat[r][c - 1] + 1);
            }
            mat[r][c] = best;
        }
    }
    for (int r = rows - 1; r >= 0; r--) {
        for (int c = cols - 1; c >= 0; c--) {
            if (r + 1 < rows) {
                mat[r][c] = smaller(mat[r][c], mat[r + 1][c] + 1);
            }
            if (c + 1 < cols) {
                mat[r][c] = smaller(mat[r][c], mat[r][c + 1] + 1);
            }
        }
    }
    return mat;
}
