class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        TreeNode inserted = new TreeNode(val);
        if (root == null) return inserted;
        TreeNode node = root;
        while (true) {
            if (val < node.val) {
                if (node.left == null) {
                    node.left = inserted;
                    return root;
                }
                node = node.left;
            } else {
                if (node.right == null) {
                    node.right = inserted;
                    return root;
                }
                node = node.right;
            }
        }
    }
}
