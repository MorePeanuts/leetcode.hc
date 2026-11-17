class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while (head != null) {
            ListNode end = head.next;
            while (end != null && end.val == head.val) {
                end = end.next;
            }
            if (head.next == end) {
                tail.next = head;
                tail = head;
            }
            head = end;
        }
        tail.next = null;
        return dummy.next;
    }
}
