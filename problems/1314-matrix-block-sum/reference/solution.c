#include <stdlib.h>

int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = matColSize[0];
    int prefix[101][101] = {0}; // m,n <= 100
    int** result = malloc((size_t)m * sizeof(*result));
    int* columns = malloc((size_t)m * sizeof(*columns));
    *returnSize = m;
    *returnColumnSizes = columns;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int top = i > k ? i - k : 0;
        int bottom = i + k + 1 < m ? i + k + 1 : m;
        result[i] = malloc((size_t)n * sizeof(*result[i]));
        columns[i] = n;
        for (int j = 0; j < n; j++) {
            int left = j > k ? j - k : 0;
            int right = j + k + 1 < n ? j + k + 1 : n;
            result[i][j] = prefix[bottom][right] - prefix[top][right] - prefix[bottom][left] + prefix[top][left];
        }
    }
    return result;
}
