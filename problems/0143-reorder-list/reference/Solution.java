class Solution {
    public void reorderList(ListNode head) {
        if (head == null) return;
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode second = slow.next;
        slow.next = null;
        ListNode previous = null;
        while (second != null) {
            ListNode next = second.next;
            second.next = previous;
            previous = second;
            second = next;
        }
        ListNode first = head;
        while (previous != null) {
            ListNode firstNext = first.next;
            ListNode secondNext = previous.next;
            first.next = previous;
            previous.next = firstNext;
            first = firstNext;
            previous = secondNext;
        }
    }
}
