function cloneGraph(node: _Node | null): _Node | null {
    if (node === null) {
        return null;
    }
    const copies = new Map<_Node, _Node>([[node, new _Node(node.val)]]);
    const queue = [node];
    for (let i = 0; i < queue.length; ++i) {
        const current = queue[i];
        const copy = copies.get(current)!;
        for (const neighbor of current.neighbors) {
            if (!copies.has(neighbor)) {
                copies.set(neighbor, new _Node(neighbor.val));
                queue.push(neighbor);
            }
            copy.neighbors.push(copies.get(neighbor)!);
        }
    }
    return copies.get(node)!;
}
