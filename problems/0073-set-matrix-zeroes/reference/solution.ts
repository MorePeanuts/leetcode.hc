function setZeroes(matrix: number[][]): void {
    let rows = matrix.length;
    let cols = matrix[0].length;
    let firstRow = false;
    let firstCol = false;
    for (let c = 0; c < cols; c++) {
        if (matrix[0][c] === 0) firstRow = true;
    }
    for (let r = 0; r < rows; r++) {
        if (matrix[r][0] === 0) firstCol = true;
    }
    for (let r = 1; r < rows; r++) {
        for (let c = 1; c < cols; c++) {
            if (matrix[r][c] === 0) matrix[r][0] = matrix[0][c] = 0;
        }
    }
    for (let r = 1; r < rows; r++) {
        for (let c = 1; c < cols; c++) {
            if (matrix[r][0] === 0 || matrix[0][c] === 0) matrix[r][c] = 0;
        }
    }
    if (firstRow) {
        for (let c = 0; c < cols; c++) matrix[0][c] = 0;
    }
    if (firstCol) {
        for (let r = 0; r < rows; r++) matrix[r][0] = 0;
    }
}
