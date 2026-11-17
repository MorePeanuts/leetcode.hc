function nearestExit(maze: string[][], entrance: number[]): number {
    let rows = maze.length;
    let cols = maze[0].length;
    const dr = [1, -1, 0, 0];
    const dc = [0, 0, 1, -1];
    const queue = new Int32Array(rows * cols);
    let head = 0;
    let tail = 0;
    let start = entrance[0] * cols + entrance[1];
    queue[tail++] = start;
    maze[entrance[0]][entrance[1]] = "+";
    let distance = 0;
    let answer = -1;
    while (head < tail && answer < 0) {
        let layerEnd = tail;
        while (head < layerEnd) {
            let id = queue[head++];
            let row = Math.floor(id / cols);
            let col = id % cols;
            if (id !== start && (row === 0 || row === rows - 1 || col === 0 || col === cols - 1)) {
                answer = distance;
                break;
            }
            for (let d = 0; d < 4; ++d) {
                let nr = row + dr[d];
                let nc = col + dc[d];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] === ".") {
                    maze[nr][nc] = "+";
                    queue[tail++] = nr * cols + nc;
                }
            }
        }
        ++distance;
    }
    return answer;
}
