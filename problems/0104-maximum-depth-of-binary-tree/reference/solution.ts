function maxDepth(root: TreeNode | null): number {
    if (root === null) {
        return 0;
    }
    const stack: [TreeNode, number][] = [];
    stack.push([root, 1]);
    let best = 0;
    while (stack.length > 0) {
        let node = stack[stack.length - 1][0];
        let depth = stack[stack.length - 1][1];
        stack.pop();
        if (depth > best) {
            best = depth;
        }
        if (node.left !== null) {
            stack.push([node.left, depth + 1]);
        }
        if (node.right !== null) {
            stack.push([node.right, depth + 1]);
        }
    }

    return best;
}
