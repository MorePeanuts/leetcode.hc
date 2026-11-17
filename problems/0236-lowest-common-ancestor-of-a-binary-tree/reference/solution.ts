function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
    if (root === null || p === null || q === null) {
        return null;
    }
    const parents = new Map<TreeNode, TreeNode | null>([[root, null]]);
    const ancestors = new Set<TreeNode>();
    const stack = [root];
    while (stack.length > 0) {
        const node = stack.pop()!;

        for (const child of [node.left, node.right]) {
            if (child != null) {
                parents.set(child, node);
                stack.push(child);
            }
        }
    }
    while (p != null) {
        ancestors.add(p);
        p = parents.get(p) ?? null;
    }
    while (!ancestors.has(q)) {
        q = parents.get(q)!;
    }
    return q;
}
