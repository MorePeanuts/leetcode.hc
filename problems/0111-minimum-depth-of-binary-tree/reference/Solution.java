class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        java.util.ArrayDeque<TreeNode> frontier = new java.util.ArrayDeque<>();
        frontier.add(root);
        int depth = 1;
        while (!frontier.isEmpty()) {
            int width = frontier.size();
            for (int i = 0; i < width; i++) {
                TreeNode node = frontier.remove();
                if (node.left == null && node.right == null) {
                    return depth;
                }
                if (node.left != null) {
                    frontier.add(node.left);
                }
                if (node.right != null) {
                    frontier.add(node.right);
                }
            }
            depth++;
        }
        return 0;
    }
}
