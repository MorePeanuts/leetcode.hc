function closedIsland(grid: number[][]): number {
    let rows = grid.length;
    let cols = grid[0].length;
    const dr = [1, -1, 0, 0];
    const dc = [0, 0, 1, -1];
    const stack = new Int32Array(rows * cols);
    let islands = 0;
    for (let r = 0; r < rows; ++r) {
        for (let c = 0; c < cols; ++c) {
            if (grid[r][c] !== 0) {
                continue;
            }
            let size = 0;
            stack[size++] = r * cols + c;
            grid[r][c] = 1;
            let closed = true;
            while (size > 0) {
                let id = stack[--size];
                let row = Math.floor(id / cols);
                let col = id % cols;
                if (row === 0 || row === rows - 1 || col === 0 || col === cols - 1) {
                    closed = false;
                }
                for (let d = 0; d < 4; ++d) {
                    let nr = row + dr[d];
                    let nc = col + dc[d];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] === 0) {
                        grid[nr][nc] = 1;
                        stack[size++] = nr * cols + nc;
                    }
                }
            }
            if (closed) {
                ++islands;
            }
        }
    }
    return islands;
}
