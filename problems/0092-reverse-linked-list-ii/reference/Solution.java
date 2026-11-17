class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(0);
        ListNode before = dummy;
        before.next = head;
        for (int i = 1; i < left; i++) {
            before = before.next;
        }
        ListNode first = before.next;
        for (int i = left; i < right; i++) {
            ListNode moved = first.next;
            first.next = moved.next;
            moved.next = before.next;
            before.next = moved;
        }
        return dummy.next;
    }
}
