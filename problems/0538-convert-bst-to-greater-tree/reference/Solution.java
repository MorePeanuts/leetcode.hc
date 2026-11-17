import java.util.ArrayDeque;


class Solution {
    public TreeNode convertBST(TreeNode root) {
        ArrayDeque<TreeNode> stack = new ArrayDeque<>();
        int total = 0;
        TreeNode node = root;
        while (node != null || !stack.isEmpty()) {
            while (node != null) {
                stack.push(node);
                node = node.right;
            }
            node = stack.peek();
            stack.pop();
            total += node.val;
            node.val = total;
            node = node.left;
        }
        return root;
    }
}
