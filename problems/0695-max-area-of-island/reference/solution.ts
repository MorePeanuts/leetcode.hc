function maxAreaOfIsland(grid: number[][]): number {
    const rows = grid.length;
    const cols = grid[0].length;
    const queue = new Int32Array(rows * cols);
    const dx = [-1, 1, 0, 0];
    const dy = [0, 0, -1, 1];
    let best = 0;
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (grid[r][c] === 0) {
                continue;
            }
            let tail = 1;
            queue[0] = r * cols + c;
            grid[r][c] = 0;
            for (let head = 0; head < tail; head++) {
                let position = queue[head];
                let x = Math.floor(position / cols);
                let y = position % cols;
                for (let d = 0; d < 4; d++) {
                    let i = x + dx[d];
                    let j = y + dy[d];
                    if (i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] === 1) {
                        grid[i][j] = 0;
                        queue[tail++] = i * cols + j;
                    }
                }
            }
            if (tail > best) {
                best = tail;
            }
        }
    }
    return best;
}
