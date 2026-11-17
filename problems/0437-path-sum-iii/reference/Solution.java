import java.util.HashMap;
import java.util.Map;

class Solution {
    private int visit(TreeNode node, long sum, int target, Map<Long, Integer> prefixes) {
        if (node == null) {
            return 0;
        }
        sum += node.val;
        int count = prefixes.getOrDefault(sum - target, 0);
        int original = prefixes.getOrDefault(sum, 0);
        prefixes.put(sum, original + 1);
        count += visit(node.left, sum, target, prefixes);
        count += visit(node.right, sum, target, prefixes);
        if (original == 0) {
            prefixes.remove(sum);
        } else {
            prefixes.put(sum, original);
        }
        return count;
    }

    public int pathSum(TreeNode root, int targetSum) {
        Map<Long, Integer> prefixes = new HashMap<>();
        prefixes.put(0L, 1);
        return visit(root, 0L, targetSum, prefixes);
    }
}
