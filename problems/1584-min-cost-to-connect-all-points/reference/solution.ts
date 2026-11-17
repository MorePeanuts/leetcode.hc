function minCostConnectPoints(points: number[][]): number {
    let n = points.length;
    const best = new Float64Array(n);
    const used = new Uint8Array(n);
    for (let i = 1; i < n; i++) best[i] = Infinity;
    best[0] = 0;
    let total = 0;
    for (let count = 0; count < n; count++) {
        let vertex = -1;
        for (let i = 0; i < n; i++) {
            if (!used[i] && (vertex < 0 || best[i] < best[vertex])) vertex = i;
        }
        used[vertex] = 1;
        total += best[vertex];
        for (let i = 0; i < n; i++) {
            if (used[i]) continue;
            let distance = Math.abs(points[vertex][0] - points[i][0]) + Math.abs(points[vertex][1] - points[i][1]);
            if (distance < best[i]) best[i] = distance;
        }
    }
    return total;
}
