class Solution {
    private boolean sameTree(TreeNode first, TreeNode second) {
        if (first == null || second == null) {
            return first == second;
        }
        return first.val == second.val
            && sameTree(first.left, second.left)
            && sameTree(first.right, second.right);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) {
            return subRoot == null;
        }
        return sameTree(root, subRoot)
            || isSubtree(root.left, subRoot)
            || isSubtree(root.right, subRoot);
    }
}
