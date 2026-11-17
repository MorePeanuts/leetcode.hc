bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int row = 0;
    int col = matrixColSize[0] - 1;
    while (row < matrixSize && col >= 0) {
        int value = matrix[row][col];
        if (value == target) {
            return true;
        }
        if (value > target) {
            --col;
        } else {
            ++row;
        }
    }
    return false;
}
