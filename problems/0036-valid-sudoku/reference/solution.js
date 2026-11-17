function isValidSudoku(board) {
    const rows = new Int32Array(9);
    const cols = new Int32Array(9);
    const boxes = new Int32Array(9);
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            if (board[i][j] === ".") continue;
            const bit = 1 << (board[i][j].charCodeAt(0) - 49);
            const box = Math.floor(i / 3) * 3 + Math.floor(j / 3);
            if ((rows[i] | cols[j] | boxes[box]) & bit) return false;
            rows[i] |= bit;
            cols[j] |= bit;
            boxes[box] |= bit;
        }
    }
    return true;
}
