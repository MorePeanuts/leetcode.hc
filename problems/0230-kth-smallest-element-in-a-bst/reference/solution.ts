function kthSmallest(root: TreeNode | null, k: number): number {
    const stack: TreeNode[] = [];
    let node = root;
    while (node !== null || stack.length > 0) {
        while (node !== null) {
            stack.push(node);
            node = node.left;
        }
        node = stack[stack.length - 1];
        stack.pop();
        if (--k === 0) {

            return node.val;
        }
        node = node.right;
    }

    return 0;
}
