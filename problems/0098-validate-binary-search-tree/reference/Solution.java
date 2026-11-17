import java.util.ArrayDeque;

class Solution {
    public boolean isValidBST(TreeNode root) {
        ArrayDeque<TreeNode> stack = new ArrayDeque<>();
        TreeNode previous = null;
        TreeNode node = root;
        while (node != null || !stack.isEmpty()) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            if (previous != null && node.val <= previous.val) return false;
            previous = node;
            node = node.right;
        }
        return true;
    }
}
