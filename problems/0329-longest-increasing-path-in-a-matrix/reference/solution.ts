function longestIncreasingPath(matrix: number[][]): number {
    let rows = matrix.length;
    let cols = matrix[0].length;
    const dr = [1, -1, 0, 0];
    const dc = [0, 0, 1, -1];
    const queue = new Int32Array(rows * cols);
    const degree = new Int32Array(rows * cols);
    let head = 0;
    let tail = 0;
    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            let id = row * cols + col;
            for (let d = 0; d < 4; ++d) {
                let nr = row + dr[d];
                let nc = col + dc[d];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[row][col]) {
                    ++degree[id];
                }
            }
            if (degree[id] === 0) {
                queue[tail++] = id;
            }
        }
    }
    let length = 0;
    while (head < tail) {
        let layerEnd = tail;
        while (head < layerEnd) {
            let id = queue[head++];
            let row = Math.floor(id / cols);
            let col = id % cols;
            for (let d = 0; d < 4; ++d) {
                let nr = row + dr[d];
                let nc = col + dc[d];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] < matrix[row][col]) {
                    let next = nr * cols + nc;
                    if (--degree[next] === 0) {
                        queue[tail++] = next;
                    }
                }
            }
        }
        ++length;
    }
    return length;
}
