import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        ArrayDeque<TreeNode> stack = new ArrayDeque<>();
        ArrayDeque<Integer> depths = new ArrayDeque<>();
        stack.push(root);
        depths.push(0);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            int depth = depths.pop();
            if (depth == result.size()) {
                result.add(node.val);
            }
            if (node.left != null) {
                stack.push(node.left);
                depths.push(depth + 1);
            }
            if (node.right != null) {
                stack.push(node.right);
                depths.push(depth + 1);
            }
        }
        return result;
    }
}
