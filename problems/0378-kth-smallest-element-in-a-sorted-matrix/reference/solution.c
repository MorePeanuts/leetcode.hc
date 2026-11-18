int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int n = matrixSize;
    int lo = matrix[0][0];
    int hi = matrix[n - 1][n - 1];
    while (lo < hi) {
        int mid = lo + (int)(((long long)hi - lo) / 2);
        int count = 0;
        int row = n - 1;
        int column = 0;
        while (row >= 0 && column < n) {
            if (matrix[row][column] <= mid) {
                count += row + 1;
                column++;
            } else {
                row--;
            }
        }
        if (count < k) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
