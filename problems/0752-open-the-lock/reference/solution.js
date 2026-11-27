function openLock(deadends, target) {
    const seen = new Uint8Array(10000);
    for (const dead of deadends) seen[Number(dead)] = 1;
    if (seen[0]) return -1;
    const goal = Number(target);
    const queue = [0];
    seen[0] = 1;
    let head = 0;
    for (let turns = 0; head < queue.length; turns++) {
        const end = queue.length;
        while (head < end) {
            const state = queue[head++];
            if (state === goal) return turns;
            for (let place = 1; place <= 1000; place *= 10) {
                const digit = Math.floor(state / place) % 10;
                const up = state + (digit === 9 ? -9 : 1) * place;
                const down = state + (digit === 0 ? 9 : -1) * place;
                for (const next of [up, down]) {
                    if (!seen[next]) {
                        seen[next] = 1;
                        queue.push(next);
                    }
                }
            }
        }
    }
    return -1;
}
