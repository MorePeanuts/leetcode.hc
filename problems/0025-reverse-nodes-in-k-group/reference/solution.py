from hc_runtime import ListNode


class Solution:
    def reverseKGroup(self, head: ListNode | None, k: int) -> ListNode | None:
        # Reverses each full group in place behind the tail of the group
        # before it; a short last group is left as it is.
        dummy = ListNode(0, head)
        before = dummy
        while True:
            end = before
            for _ in range(k):
                end = end.next
                if end is None:
                    return dummy.next
            after = end.next
            prev, cur = after, before.next
            while cur is not after:
                cur.next, prev, cur = prev, cur, cur.next
            first = before.next
            before.next = end
            before = first
