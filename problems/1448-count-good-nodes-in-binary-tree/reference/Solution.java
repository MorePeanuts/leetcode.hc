import java.util.ArrayDeque;

class Solution {
    private record Entry(TreeNode node, int high) {}

    public int goodNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        ArrayDeque<Entry> stack = new ArrayDeque<>();
        stack.push(new Entry(root, root.val));
        int result = 0;
        while (!stack.isEmpty()) {
            Entry entry = stack.peek();
            stack.pop();
            int high = entry.high();
            if (entry.node().val >= high) {
                result++;
                high = entry.node().val;
            }
            if (entry.node().left != null) {
                stack.push(new Entry(entry.node().left, high));
            }
            if (entry.node().right != null) {
                stack.push(new Entry(entry.node().right, high));
            }
        }

        return result;
    }
}
