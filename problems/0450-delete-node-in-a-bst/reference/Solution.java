class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode parent = null;
        TreeNode node = root;
        while (node != null && node.val != key) {
            parent = node;
            node = key < node.val ? node.left : node.right;
        }
        if (node == null) {
            return root;
        }
        if (node.left != null && node.right != null) {
            TreeNode successorParent = node;
            TreeNode successor = node.right;
            while (successor.left != null) {
                successorParent = successor;
                successor = successor.left;
            }
            node.val = successor.val;
            parent = successorParent;
            node = successor;
        }
        TreeNode child = node.left != null ? node.left : node.right;
        if (parent == null) {
            return child;
        }
        if (parent.left == node) {
            parent.left = child;
        } else {
            parent.right = child;
        }
        return root;
    }
}
