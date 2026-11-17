import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;
        List<TreeNode> queue = new ArrayList<>();
        queue.add(root);
        for (int head = 0; head < queue.size();) {
            int limit = queue.size();
            List<Integer> values = new ArrayList<>(limit - head);
            for (int i = 0; head < limit; i++) {
                TreeNode node = queue.get(head++);
                values.add(node.val);
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
            result.add(values);
        }
        return result;
    }
}
