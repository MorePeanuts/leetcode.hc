import java.util.ArrayList;
import java.util.List;

class Solution {
    public boolean isCompleteTree(TreeNode root) {
        List<TreeNode> queue = new ArrayList<>();
        queue.add(root);
        int head = 0;
        boolean gap = false;
        while (head < queue.size()) {
            TreeNode node = queue.get(head++);
            if (node == null) {
                gap = true;
            } else {
                if (gap) {
                    return false;
                }
                queue.add(node.left);
                queue.add(node.right);
            }
        }
        return true;
    }
}
