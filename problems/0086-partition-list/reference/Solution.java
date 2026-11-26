class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode small = new ListNode(), large = new ListNode();
        ListNode smallTail = small, largeTail = large;
        while (head != null) {
            if (head.val < x) {
                smallTail.next = head;
                smallTail = head;
            } else {
                largeTail.next = head;
                largeTail = head;
            }
            head = head.next;
        }
        largeTail.next = null;
        smallTail.next = large.next;
        return small.next;
    }
}
