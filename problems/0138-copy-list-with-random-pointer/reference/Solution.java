class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        for (Node node = head; node != null; node = node.next.next) {
            Node copy = new Node(node.val);
            copy.next = node.next;
            node.next = copy;
        }
        for (Node node = head; node != null; node = node.next.next) {
            node.next.random = node.random == null ? null : node.random.next;
        }
        Node result = head.next;
        for (Node node = head; node != null; node = node.next) {
            Node copy = node.next;
            node.next = copy.next;
            copy.next = node.next == null ? null : node.next.next;
        }
        return result;
    }
}
