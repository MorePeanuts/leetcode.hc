function rotate(matrix: number[][]): void {
    let n = matrix.length;
    for (let row = 0; row < n; ++row) {
        for (let col = row + 1; col < n; ++col) {
            let temp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
        }
    }
    for (let row = 0; row < n; ++row) {
        for (let left = 0, right = n - 1; left < right; ++left, --right) {
            let temp = matrix[row][left];
            matrix[row][left] = matrix[row][right];
            matrix[row][right] = temp;
        }
    }
}
