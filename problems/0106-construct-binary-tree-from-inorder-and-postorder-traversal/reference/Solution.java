import java.util.ArrayDeque;

class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        TreeNode root = new TreeNode(postorder[n - 1]);
        ArrayDeque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);
        int index = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            TreeNode node = stack.peek();
            TreeNode child = new TreeNode(postorder[i]);
            if (node.val != inorder[index]) {
                node.right = child;
            } else {
                while (!stack.isEmpty() && stack.peek().val == inorder[index]) {
                    node = stack.pop();
                    index--;
                }
                node.left = child;
            }
            stack.push(child);
        }
        return root;
    }
}
