class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode previous = null;
        while (slow != null) {
            ListNode next = slow.next;
            slow.next = previous;
            previous = slow;
            slow = next;
        }
        ListNode left = head;
        while (previous != null) {
            if (left.val != previous.val) return false;
            left = left.next;
            previous = previous.next;
        }
        return true;
    }
}
