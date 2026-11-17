import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        TreeNode[] parents = new TreeNode[501];
            TreeNode[] queue = new TreeNode[500];
            boolean[] seen = new boolean[501];
        queue[0] = root;
        int tail = 1;
        for (int head = 0; head < tail; head++) {
            TreeNode node = queue[head];
            if (node.left != null) {
                parents[node.left.val] = node;
                queue[tail++] = node.left;
            }
            if (node.right != null) {
                parents[node.right.val] = node;
                queue[tail++] = node.right;
            }
        }
        queue[0] = target;
        seen[target.val] = true;
        tail = 1;
        int head = 0;
        for (int depth = 0; depth < k && head < tail; depth++) {
            int levelEnd = tail;
            for (; head < levelEnd; head++) {
                TreeNode node = queue[head];
                TreeNode[] neighbors = {node.left, node.right, parents[node.val]};
                for (TreeNode neighbor : neighbors) {

                    if (neighbor != null && !seen[neighbor.val]) {
                        seen[neighbor.val] = true;
                        queue[tail++] = neighbor;
                    }
                }
            }
        }
        List<Integer> result = new ArrayList<>(tail - head);
            for (int i = head; i < tail; i++) result.add(queue[i].val);
            return result;
    }
}
