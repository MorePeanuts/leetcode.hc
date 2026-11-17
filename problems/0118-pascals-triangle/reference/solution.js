function generate(numRows) {
    const rows = [];
    for (let row = 0; row < numRows; ++row) {
        const next = new Array(row + 1).fill(1);
        for (let col = 1; col < row; ++col) {
            next[col] = rows[row - 1][col - 1] + rows[row - 1][col];
        }
        rows.push(next);
    }
    return rows;
}
