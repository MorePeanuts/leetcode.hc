import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        List<TreeNode> queue = new ArrayList<>();
        queue.add(root);
        int head = 0;
        boolean forward = true;
        while (head < queue.size()) {
            int end = queue.size();
            int width = end - head;
            Integer[] row = new Integer[width];
            for (int i = 0; i < width; i++) {
                TreeNode node = queue.get(head++);
                row[forward ? i : width - 1 - i] = node.val;
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            result.add(Arrays.asList(row));
            forward = !forward;
        }
        return result;
    }
}
