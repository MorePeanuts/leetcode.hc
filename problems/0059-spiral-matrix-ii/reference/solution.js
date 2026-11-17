function generateMatrix(n) {
    const matrix = Array.from({ length: n }, () => new Array(n).fill(0));
    let row = 0;
    let col = 0;
    let dr = 0;
    let dc = 1;
    for (let value = 1; value <= n * n; ++value) {
        matrix[row][col] = value;
        let nr = row + dr;
        let nc = col + dc;
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || matrix[nr][nc] !== 0) {
            let oldDr = dr;
            dr = dc;
            dc = -oldDr;
        }
        row += dr;
        col += dc;
    }
    return matrix;
}
