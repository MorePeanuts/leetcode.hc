#include <stdbool.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    bool firstRow = false;
    bool firstCol = false;
    for (int c = 0; c < cols; c++) {
        if (matrix[0][c] == 0) firstRow = true;
    }
    for (int r = 0; r < rows; r++) {
        if (matrix[r][0] == 0) firstCol = true;
    }
    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (matrix[r][c] == 0) matrix[r][0] = matrix[0][c] = 0;
        }
    }
    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
        }
    }
    if (firstRow) {
        for (int c = 0; c < cols; c++) matrix[0][c] = 0;
    }
    if (firstCol) {
        for (int r = 0; r < rows; r++) matrix[r][0] = 0;
    }
}
