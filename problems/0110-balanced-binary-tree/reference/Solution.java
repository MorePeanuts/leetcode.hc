import java.util.ArrayList;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        List<TreeNode> order = new ArrayList<>();
        order.add(root);
        for (int i = 0; i < order.size(); i++) {
            TreeNode node = order.get(i);
            if (node.left != null) order.add(node.left);
            if (node.right != null) order.add(node.right);
        }
        Map<TreeNode, Integer> heights = new IdentityHashMap<>();
        for (int i = order.size() - 1; i >= 0; i--) {
            TreeNode node = order.get(i);
            int left = node.left == null ? 0 : heights.get(node.left);
            int right = node.right == null ? 0 : heights.get(node.right);
            if (Math.abs(left - right) > 1) return false;
            heights.put(node, 1 + Math.max(left, right));
        }
        return true;
    }
}
