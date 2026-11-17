function minimumEffortPath(heights: number[][]): number {
    const rows = heights.length;
    const cols = heights[0].length;
    let total = rows * cols;
    const best = new Int32Array(total).fill(1000000);
    const queue = new MinPriorityQueue((entry: {position: number; cost: number}) => entry.cost);
    best[0] = 0;
    queue.enqueue({position: 0, cost: 0});
    const dr = [-1, 1, 0, 0];
    const dc = [0, 0, -1, 1];
    while (!queue.isEmpty()) {
        const {position, cost} = queue.dequeue()!;
        if (cost !== best[position]) {
            continue;
        }
        if (position === total - 1) {

            return cost;
        }
        let r = Math.floor(position / cols);
        let c = position % cols;
        for (let d = 0; d < 4; d++) {
            let nr = r + dr[d];
            let nc = c + dc[d];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                continue;
            }
            let next = nr * cols + nc;
            let difference = Math.abs(heights[r][c] - heights[nr][nc]);
            let candidate = cost > difference ? cost : difference;
            if (candidate < best[next]) {
                best[next] = candidate;
                queue.enqueue({position: next, cost: candidate});
            }
        }
    }

    return 0;
}
