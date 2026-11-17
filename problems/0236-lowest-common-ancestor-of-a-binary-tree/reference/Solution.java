import java.util.ArrayDeque;
import java.util.Collections;
import java.util.Deque;
import java.util.IdentityHashMap;
import java.util.Map;
import java.util.Set;

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        Map<TreeNode, TreeNode> parents = new IdentityHashMap<>();
        parents.put(root, null);
        Set<TreeNode> ancestors = Collections.newSetFromMap(new IdentityHashMap<>());
        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            TreeNode[] children = {node.left, node.right};
            for (TreeNode child : children) {
                if (child != null) {
                    parents.put(child, node);
                    stack.push(child);
                }
            }
        }
        while (p != null) {
            ancestors.add(p);
            p = parents.get(p);
        }
        while (!ancestors.contains(q)) {
            q = parents.get(q);
        }
        return q;
    }
}
