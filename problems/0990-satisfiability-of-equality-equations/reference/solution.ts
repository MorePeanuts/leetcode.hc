function equationsPossible(equations: string[]): boolean {
    const parent = new Int32Array(26);
    const size = new Int32Array(26);
    for (let i = 0; i < 26; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    function find(node: number): number {
        while (parent[node] !== node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    for (let i = 0; i < equations.length; i++) {
        if (equations[i][1] === '=') {
            let a = find(equations[i].charCodeAt(0) - 97);
            let b = find(equations[i].charCodeAt(3) - 97);
            if (a === b) continue;
            if (size[a] < size[b]) {
                let temporary = a;
                a = b;
                b = temporary;
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
    for (let i = 0; i < equations.length; i++) {
        if (equations[i][1] === '!' && find(equations[i].charCodeAt(0) - 97) === find(equations[i].charCodeAt(3) - 97)) return false;
    }
    return true;
}
