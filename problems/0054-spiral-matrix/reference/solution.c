int *spiralOrder(int **matrix, int rows, int *columnSizes, int *returnSize) {
    int columns = columnSizes[0];
    *returnSize = rows * columns;
    int *result = malloc(*returnSize * sizeof(*result));
    int index = 0;
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = columns - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            result[index++] = matrix[top][j];
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[index++] = matrix[bottom][j];
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    return result;
}
