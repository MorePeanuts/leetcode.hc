class Solution {
    private static ListNode splitRun(ListNode node, int size) {
    if (node == null) {
            return null;
        }
        for (int i = 1; i < size && node.next != null; i++) {
            node = node.next;
        }
        ListNode rest = node.next;
        node.next = null;
        return rest;
    }

    public ListNode sortList(ListNode head) {
        int length = 0;
        ListNode node = head;
        while (node != null) {
            length++;
            node = node.next;
        }
        ListNode dummy = new ListNode(0);
        ListNode sentinel = dummy;
        sentinel.next = head;
        for (int width = 1; width < length; width *= 2) {
            ListNode tail = sentinel;
            ListNode current = sentinel.next;
            while (current != null) {
                ListNode left = current;
                ListNode right = splitRun(left, width);
                current = splitRun(right, width);
                while (left != null && right != null) {
                    if (left.val <= right.val) {
                        tail.next = left;
                        left = left.next;
                    } else {
                        tail.next = right;
                        right = right.next;
                    }
                    tail = tail.next;
                }
                tail.next = left != null ? left : right;
                while (tail.next != null) {
                    tail = tail.next;
                }
            }
        }
        return sentinel.next;
    }
}
