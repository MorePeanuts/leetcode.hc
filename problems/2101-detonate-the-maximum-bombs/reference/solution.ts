function maximumDetonation(bombs: number[][]): number {
    const edges: number[][] = Array.from({length: bombs.length}, () => []);
    for (let i = 0; i < bombs.length; i++) {
        const [x, y, radius] = bombs[i];
        for (let j = 0; j < bombs.length; j++) {
            const dx = x - bombs[j][0];
            const dy = y - bombs[j][1];
            if (i !== j && dx * dx + dy * dy <= radius * radius) edges[i].push(j);
        }
    }
    let best = 0;
    for (let start = 0; start < bombs.length; start++) {
        const seen = new Set([start]);
        const queue = [start];
        for (let head = 0; head < queue.length; head++) {
            for (const next of edges[queue[head]]) {
                if (!seen.has(next)) {
                    seen.add(next);
                    queue.push(next);
                }
            }
        }
        best = Math.max(best, queue.length);
        if (best === bombs.length) break;
    }
    return best;
}
