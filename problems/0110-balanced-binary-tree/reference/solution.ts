function isBalanced(root: TreeNode | null): boolean {
    if (root === null) return true;
    const order = [root];
    for (let i = 0; i < order.length; i++) {
        const node = order[i];
        if (node.left !== null) order.push(node.left);
        if (node.right !== null) order.push(node.right);
    }
    const heights = new Map<TreeNode, number>();
    for (let i = order.length - 1; i >= 0; i--) {
        const node = order[i];
        const left = node.left === null ? 0 : heights.get(node.left)!;
        const right = node.right === null ? 0 : heights.get(node.right)!;
        if (Math.abs(left - right) > 1) return false;
        heights.set(node, 1 + Math.max(left, right));
    }
    return true;
}
