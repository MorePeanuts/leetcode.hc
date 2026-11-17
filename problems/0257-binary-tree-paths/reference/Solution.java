import java.util.ArrayList;
import java.util.List;

class Solution {
    private void visit(TreeNode node, String path, List<String> result) {
        if (node == null) {
            return;
        }
        String next = path.isEmpty() ? String.valueOf(node.val) : path + "->" + node.val;
        if (node.left == null && node.right == null) {
            result.add(next);
            return;
        }
        visit(node.left, next, result);
        visit(node.right, next, result);
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result = new ArrayList<>();
        visit(root, "", result);
        return result;
    }
}
