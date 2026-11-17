import java.util.ArrayDeque;
import java.util.Deque;

record Frame(TreeNode node, int depth) {}

class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Deque<Frame> stack = new ArrayDeque<>();
        stack.push(new Frame(root, 1));
        int best = 0;
        while (!stack.isEmpty()) {
            TreeNode node = stack.peek().node();
            int depth = stack.peek().depth();
            stack.pop();
            if (depth > best) {
                best = depth;
            }
            if (node.left != null) {
                stack.push(new Frame(node.left, depth + 1));
            }
            if (node.right != null) {
                stack.push(new Frame(node.right, depth + 1));
            }
        }

        return best;
    }
}
