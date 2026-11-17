import java.util.ArrayList;
import java.util.List;

class Solution {
    private void visit(TreeNode node, List<Integer> result) {
        if (node == null) {
            return;
        }
        visit(node.left, result);
        visit(node.right, result);
        result.add(node.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        visit(root, result);
        return result;
    }
}
