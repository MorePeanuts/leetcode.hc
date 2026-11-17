function convertBST(root: TreeNode | null): TreeNode | null {
    const stack: TreeNode[] = [];
    let total = 0;
    let node: TreeNode | null = root;
    while (node !== null || stack.length > 0) {
        while (node !== null) {
            stack.push(node);
            node = node.right;
        }
        node = stack[stack.length - 1];
        stack.pop();
        total += node.val;
        node.val = total;
        node = node.left;
    }
    return root;
}
