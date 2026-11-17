function shortestPathBinaryMatrix(grid) {
    const rows = grid.length;
    if (grid[0][0] !== 0 || grid[rows - 1][rows - 1] !== 0) {
        return -1;
    }
    const queue = new Int32Array(rows * rows);
    queue[0] = 0;
    grid[0][0] = 1;
    let head = 0;
    let tail = 1;
    let distance = 1;
    while (head < tail) {
        let end = tail;
        while (head < end) {
            let position = queue[head++];
            if (position === rows * rows - 1) {
                return distance;
            }
            let r = Math.floor(position / rows);
            let c = position % rows;
            for (let i = r - 1; i <= r + 1; i++) {
                for (let j = c - 1; j <= c + 1; j++) {
                    if (i >= 0 && i < rows && j >= 0 && j < rows && grid[i][j] === 0) {
                        grid[i][j] = 1;
                        queue[tail++] = i * rows + j;
                    }
                }
            }
        }
        distance++;
    }
    return -1;
}
