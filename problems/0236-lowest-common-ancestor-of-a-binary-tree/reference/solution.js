function lowestCommonAncestor(root, p, q) {
    const parents = new Map([[root, null]]);
    const ancestors = new Set();
    const stack = [root];
    while (stack.length > 0) {
        const node = stack.pop();

        for (const child of [node.left, node.right]) {
            if (child != null) {
                parents.set(child, node);
                stack.push(child);
            }
        }
    }
    while (p != null) {
        ancestors.add(p);
        p = parents.get(p);
    }
    while (!ancestors.has(q)) {
        q = parents.get(q);
    }
    return q;
}
