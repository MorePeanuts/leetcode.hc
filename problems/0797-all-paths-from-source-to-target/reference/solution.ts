function allPathsSourceTarget(graph: number[][]): number[][] {
    const size = graph.length;
    const result: number[][] = [];
    const path: number[] = [0];
    function visit(node: number): void {
        if (node === size - 1) {
            result.push(path.slice());
            return;
        }
        for (let i = 0; i < graph[node].length; ++i) {
            let value = graph[node][i];
            path.push(value);
            visit(value);
            path.pop();
        }
    }
    visit(0);
    return result;
}
