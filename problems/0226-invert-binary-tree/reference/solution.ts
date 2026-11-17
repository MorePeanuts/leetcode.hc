function invertTree(root: TreeNode | null): TreeNode | null {
    if (root === null) {
        return null;
    }
    let left: TreeNode | null = root.left;
    root.left = invertTree(root.right);
    root.right = invertTree(left);
    return root;
}
