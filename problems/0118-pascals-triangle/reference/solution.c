int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** rows = malloc((size_t)numRows * sizeof(*rows));
    *returnSize = numRows;
    *returnColumnSizes = malloc((size_t)numRows * sizeof(**returnColumnSizes));
    for (int row = 0; row < numRows; ++row) {
        rows[row] = malloc((size_t)(row + 1) * sizeof(*rows[row]));
        (*returnColumnSizes)[row] = row + 1;
        rows[row][0] = 1;
        for (int col = 1; col < row; ++col) {
            rows[row][col] = rows[row - 1][col - 1] + rows[row - 1][col];
        }
        rows[row][row] = 1;
    }
    return rows;
}
