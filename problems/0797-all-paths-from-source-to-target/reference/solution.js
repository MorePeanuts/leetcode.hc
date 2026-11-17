function allPathsSourceTarget(graph) {
    const size = graph.length;
    const result = [];
    const path = [0];
    function visit(node) {
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
