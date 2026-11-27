function minMutation(startGene: string, endGene: string, bank: string[]): number {
    const queue = [startGene];
    const seen = new Set(queue);
    let head = 0;
    for (let steps = 0; head < queue.length; steps++) {
        const end = queue.length;
        while (head < end) {
            const current = queue[head++];
            if (current === endGene) return steps;
            for (const next of bank) {
                if (seen.has(next)) continue;
                let differences = 0;
                for (let i = 0; i < current.length; i++) {
                    if (current[i] !== next[i]) differences++;
                }
                if (differences === 1) {
                    seen.add(next);
                    queue.push(next);
                }
            }
        }
    }
    return -1;
}
