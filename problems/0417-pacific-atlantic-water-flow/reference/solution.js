function pacificAtlantic(heights) {
    const rows = heights.length;
    const cols = heights[0].length;
    function reach(far) {
        const seen = new Uint8Array(rows * cols);
        const queue = new Int32Array(rows * cols);
        let head = 0;
        let tail = 0;
        let side = far ? cols - 1 : 0;
        let edge = far ? rows - 1 : 0;
        for (let r = 0; r < rows; r++) {
            let index = r * cols + side;
            seen[index] = 1;
            queue[tail++] = index;
        }
        for (let c = 0; c < cols; c++) {
            let index = edge * cols + c;
            if (!seen[index]) {
                seen[index] = 1;
                queue[tail++] = index;
            }
        }
        const dy = [-1, 1, 0, 0];
        const dx = [0, 0, -1, 1];
        while (head < tail) {
            let index = queue[head++];
            let row = Math.floor(index / cols);
            let col = index % cols;
            for (let d = 0; d < 4; d++) {
                let r = row + dy[d];
                let c = col + dx[d];
                if (r < 0 || r >= rows || c < 0 || c >= cols) {
                    continue;
                }
                let next = r * cols + c;
                if (!seen[next] && heights[r][c] >= heights[row][col]) {
                    seen[next] = 1;
                    queue[tail++] = next;
                }
            }
        }
        return seen;
    }
    const pacific = reach(false);
    const atlantic = reach(true);
    const result = [];
    for (let i = 0; i < pacific.length; i++) {
        if (pacific[i] && atlantic[i]) {
            result.push([Math.floor(i / cols), i % cols]);
        }
    }
    return result;
}
