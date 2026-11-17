function numIslands(grid: string[][]): number {
    let rows = grid.length;
    let cols = grid[0].length;
    const dr = [1, -1, 0, 0];
    const dc = [0, 0, 1, -1];
    const queue = new Int32Array(rows * cols);
    let islands = 0;
    for (let r = 0; r < rows; ++r) {
        for (let c = 0; c < cols; ++c) {
            if (grid[r][c] !== "1") {
                continue;
            }
            ++islands;
            let head = 0;
            let tail = 0;
            queue[tail++] = r * cols + c;
            grid[r][c] = "0";
            while (head < tail) {
                let id = queue[head++];
                let row = Math.floor(id / cols);
                let col = id % cols;
                for (let d = 0; d < 4; ++d) {
                    let nr = row + dr[d];
                    let nc = col + dc[d];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] === "1") {
                        grid[nr][nc] = "0";
                        queue[tail++] = nr * cols + nc;
                    }
                }
            }
        }
    }
    return islands;
}
