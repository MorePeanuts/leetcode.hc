function orangesRotting(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const queue = new Int32Array(rows * cols);
    const dx = [-1, 1, 0, 0];
    const dy = [0, 0, -1, 1];
    let fresh = 0;
    let head = 0;
    let tail = 0;
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (grid[r][c] === 2) {
                queue[tail++] = r * cols + c;
            } else if (grid[r][c] === 1) {
                fresh++;
            }
        }
    }
    let minutes = 0;
    while (head < tail && fresh > 0) {
        let end = tail;
        while (head < end) {
            let position = queue[head++];
            let x = Math.floor(position / cols);
            let y = position % cols;
            for (let d = 0; d < 4; d++) {
                let i = x + dx[d];
                let j = y + dy[d];
                if (i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] === 1) {
                    grid[i][j] = 2;
                    fresh--;
                    queue[tail++] = i * cols + j;
                }
            }
        }
        minutes++;
    }
    return fresh === 0 ? minutes : -1;
}
