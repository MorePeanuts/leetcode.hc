function cloneGraph(node) {
    if (node === null) {
        return null;
    }
    const copies = new Map([[node, new Node(node.val)]]);
    const queue = [node];
    for (let i = 0; i < queue.length; ++i) {
        const current = queue[i];
        const copy = copies.get(current);
        for (const neighbor of current.neighbors) {
            if (!copies.has(neighbor)) {
                copies.set(neighbor, new Node(neighbor.val));
                queue.push(neighbor);
            }
            copy.neighbors.push(copies.get(neighbor));
        }
    }
    return copies.get(node);
}
