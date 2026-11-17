import java.util.ArrayList;

class Solution {
    private record Entry(TreeNode node, long index) {}

    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        ArrayList<Entry> queue = new ArrayList<>();
        queue.add(new Entry(root, 0));
        int head = 0;
        int best = 0;
        while (head < queue.size()) {
            int end = queue.size();
            long base = queue.get(head).index();
            int width = (int)(queue.get(end - 1).index() - base + 1);
            if (width > best) {
                best = width;
            }
            while (head < end) {
                TreeNode node = queue.get(head).node();
                long index = queue.get(head).index() - base;
                head++;
                if (node.left != null) {
                    queue.add(new Entry(node.left, 2 * index));
                }
                if (node.right != null) {
                    queue.add(new Entry(node.right, 2 * index + 1));
                }
            }
        }
        return best;
    }
}
