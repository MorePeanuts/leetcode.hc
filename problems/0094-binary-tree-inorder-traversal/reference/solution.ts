function inorderTraversal(root: TreeNode | null): number[] {
    const stack: TreeNode[] = [];
    const result: number[] = [];
    let node = root;
    while (node !== null || stack.length > 0) {
        while (node !== null) {
            stack.push(node);
            node = node.left;
        }
        node = stack.pop()!;
        result.push(node.val);
        node = node.right;
    }
    return result;
}
