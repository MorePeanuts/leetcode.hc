function searchMatrix(matrix: number[][], target: number): boolean {
    let row = 0;
    let col = matrix[0].length - 1;
    while (row < matrix.length && col >= 0) {
        let value = matrix[row][col];
        if (value === target) {
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
