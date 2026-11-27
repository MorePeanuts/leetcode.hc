function updateMatrix(mat: number[][]): number[][] {
    const rows = mat.length, cols = mat[0].length;
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (mat[r][c] === 0) {
                continue;
            }
            let best = rows + cols;
            if (r > 0) {
                best = Math.min(best, mat[r - 1][c] + 1);
            }
            if (c > 0) {
                best = Math.min(best, mat[r][c - 1] + 1);
            }
            mat[r][c] = best;
        }
    }
    for (let r = rows - 1; r >= 0; r--) {
        for (let c = cols - 1; c >= 0; c--) {
            if (r + 1 < rows) {
                mat[r][c] = Math.min(mat[r][c], mat[r + 1][c] + 1);
            }
            if (c + 1 < cols) {
                mat[r][c] = Math.min(mat[r][c], mat[r][c + 1] + 1);
            }
        }
    }
    return mat;
}
