bool searchMatrix(int **matrix, int rows, int *columnSizes, int target) {
    int columns = columnSizes[0];
    int low = 0;
    int high = rows * columns - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int value = matrix[mid / columns][mid % columns];
        if (value == target) {
            return true;
        }
        if (value < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
