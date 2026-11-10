from hc_runtime import ListNode


class Solution:
    def reverseBetween(
        self, head: ListNode | None, left: int, right: int
    ) -> ListNode | None:
        # One pass: walk to the node before position left, then move each
        # following node of the stretch to its front.
        dummy = ListNode(0, head)
        before = dummy
        for _ in range(left - 1):
            before = before.next
        first = before.next
        for _ in range(right - left):
            moved = first.next
            first.next = moved.next
            moved.next = before.next
            before.next = moved
        return dummy.next
