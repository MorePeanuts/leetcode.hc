function calcEquation(equations: string[][], values: number[], queries: string[][]): number[] {
    const graph = new Map<string, [string, number][]>();
    function add(from: string, to: string, ratio: number) {
        if (!graph.has(from)) graph.set(from, []);
        graph.get(from)!.push([to, ratio]);
    }
    for (let i = 0; i < equations.length; i++) {
        const [a, b] = equations[i];
        add(a, b, values[i]);
        add(b, a, 1 / values[i]);
    }
    function quotient(start: string, target: string): number {
        if (!graph.has(start) || !graph.has(target)) return -1;
        const seen = new Set([start]);
        const queue: [string, number][] = [[start, 1]];
        for (let i = 0; i < queue.length; i++) {
            const [node, product] = queue[i];
            if (node === target) return product;
            for (const [next, ratio] of graph.get(node)!) {
                if (!seen.has(next)) {
                    seen.add(next);
                    queue.push([next, product * ratio]);
                }
            }
        }
        return -1;
    }
    return queries.map(([a, b]) => quotient(a, b));
}
