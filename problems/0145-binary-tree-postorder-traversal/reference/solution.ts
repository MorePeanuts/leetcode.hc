function postorderTraversal(root: TreeNode | null): number[] {
    const result: number[] = [];
    function visit(node: TreeNode | null): void {
        if (node === null) {
            return;
        }
        visit(node.left);
        visit(node.right);
        result.push(node.val);
    }
    visit(root);
    return result;
}
