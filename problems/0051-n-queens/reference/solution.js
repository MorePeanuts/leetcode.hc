function solveNQueens(n) {
    const result = [];
    const placement = new Array(n).fill(0);

    function visit(row, columns, down, up) {
        if (row === n) {
            result.push(placement.map(col => ".".repeat(col) + "Q" + ".".repeat(n - col - 1)));
            return;
        }
        for (let col = 0; col < n; ++col) {
            let columnBit = 1 << col;
            let downBit = 1 << (row - col + n - 1);
            let upBit = 1 << (row + col);
            if ((columns & columnBit) !== 0 || (down & downBit) !== 0 || (up & upBit) !== 0) {
                continue;
            }
            placement[row] = col;
            visit(row + 1, columns | columnBit, down | downBit, up | upBit);
        }
    }

    visit(0, 0, 0, 0);
    return result;
}
