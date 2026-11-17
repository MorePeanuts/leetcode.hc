function searchMatrix(matrix: number[][], target: number): boolean {
    const rows = matrix.length;
    const columns = matrix[0].length;
    let low = 0;
    let high = rows * columns - 1;
    while (low <= high) {
        let mid = low + Math.floor((high - low) / 2);
        let value = matrix[Math.floor(mid / columns)][mid % columns];
        if (value === target) {
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
