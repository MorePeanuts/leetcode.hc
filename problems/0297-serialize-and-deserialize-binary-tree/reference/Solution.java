import java.util.ArrayDeque;

class Codec {
    private void appendNode(StringBuilder data, ArrayDeque<TreeNode> queue, TreeNode node) {
        if (node == null) {
            data.append('#');
        } else {
            data.append(node.val);
            queue.addLast(node);
        }
        data.append(',');
    }

    public String serialize(TreeNode root) {
        StringBuilder data = new StringBuilder();
        ArrayDeque<TreeNode> queue = new ArrayDeque<>();
        appendNode(data, queue, root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.removeFirst();
            appendNode(data, queue, node.left);
            appendNode(data, queue, node.right);
        }
        return data.toString();
    }

    private TreeNode readNode(String token, ArrayDeque<TreeNode> queue) {
        if (token.equals("#")) {
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(token));
        queue.addLast(node);
        return node;
    }

    public TreeNode deserialize(String data) {
        String[] tokens = data.split(",");
        ArrayDeque<TreeNode> queue = new ArrayDeque<>();
        TreeNode root = readNode(tokens[0], queue);
        int next = 1;
        while (!queue.isEmpty()) {
            TreeNode parent = queue.removeFirst();
            parent.left = readNode(tokens[next++], queue);
            parent.right = readNode(tokens[next++], queue);
        }
        return root;
    }
}
