class Solution {
    private int sumFrom(TreeNode node, int prefix) {
        if (node == null) {
            return 0;
        }
        int value = prefix * 10 + node.val;
        if (node.left == null && node.right == null) {
            return value;
        }
        return sumFrom(node.left, value) + sumFrom(node.right, value);
    }

    public int sumNumbers(TreeNode root) {
        return sumFrom(root, 0);
    }
}
