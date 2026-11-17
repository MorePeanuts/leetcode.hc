function solve(board) {
    const rows = board.length;
    const cols = board[0].length;
    const stack = [];
    function mark(row, col) {
        if (board[row][col] !== 'O') return;
        board[row][col] = '#';
        stack.push(row * cols + col);
    }
    for (let row = 0; row < rows; row++) {
        mark(row, 0);
        mark(row, cols - 1);
    }
    for (let col = 0; col < cols; col++) {
        mark(0, col);
        mark(rows - 1, col);
    }
    while (stack.length > 0) {
        const cell = stack.pop();
        const row = Math.floor(cell / cols);
        const col = cell % cols;
        if (row > 0) mark(row - 1, col);
        if (row + 1 < rows) mark(row + 1, col);
        if (col > 0) mark(row, col - 1);
        if (col + 1 < cols) mark(row, col + 1);
    }
    for (const row of board)
        for (let col = 0; col < cols; col++) row[col] = row[col] === '#' ? 'O' : 'X';
}
