class Solution {
    public Node connect(Node root) {
        Node level = root;
        while (level != null) {
            Node dummy = new Node(0, null, null, null);
            Node tail = dummy;
            Node node = level;
            while (node != null) {
                if (node.left != null) {
                    tail.next = node.left;
                    tail = tail.next;
                }
                if (node.right != null) {
                    tail.next = node.right;
                    tail = tail.next;
                }
                node = node.next;
            }
            level = dummy.next;
        }
        return root;
    }
}
