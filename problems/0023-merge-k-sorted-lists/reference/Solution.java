class Solution {
    private static ListNode mergeTwo(ListNode a, ListNode b) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while (a != null && b != null) {
            if (a.val <= b.val) {
                tail.next = a;
                a = a.next;
            } else {
                tail.next = b;
                b = b.next;
            }
            tail = tail.next;
        }
        tail.next = a != null ? a : b;
        return dummy.next;
    }

    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;

        for (int step = 1; step < n; step *= 2) {
            for (int i = 0; i + step < n; i += 2 * step) {
                lists[i] = mergeTwo(lists[i], lists[i + step]);
            }
        }
        return n == 0 ? null : lists[0];
    }
}
