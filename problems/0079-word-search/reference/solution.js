function exist(board, word) {
    const rows = board.length;
    const cols = board[0].length;
    const length = word.length;

    function visit(row, col, index) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] !== word[index]) {
            return false;
        }
        if (index + 1 === length) {
            return true;
        }
        const original = board[row][col];
        board[row][col] = "#";
        const found = visit(row + 1, col, index + 1)
            || visit(row - 1, col, index + 1)
            || visit(row, col + 1, index + 1)
            || visit(row, col - 1, index + 1);
        board[row][col] = original;
        return found;
    }

    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            if (visit(row, col, 0)) {
                return true;
            }
        }
    }
    return false;
}
