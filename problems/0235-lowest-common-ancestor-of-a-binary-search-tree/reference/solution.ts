function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
    while (root !== null) {
        if (root.val > p!.val && root.val > q!.val) {
            root = root.left;
        } else if (root.val < p!.val && root.val < q!.val) {
            root = root.right;
        } else {
            break;
        }
    }
    return root;
}
