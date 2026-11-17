function isValidBST(root: TreeNode | null): boolean {
    const stack: TreeNode[] = [];
    let previous: TreeNode | null = null;
    let node = root;
    while (node !== null || stack.length > 0) {
        while (node !== null) {
            stack.push(node);
            node = node.left;
        }
        node = stack.pop()!;
        if (previous !== null && node.val <= previous.val) return false;
        previous = node;
        node = node.right;
    }
    return true;
}
