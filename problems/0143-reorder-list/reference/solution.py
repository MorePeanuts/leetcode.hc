from hc_runtime import ListNode


class Solution:
    def reorderList(self, head: ListNode | None) -> None:
        # Split the list at its middle, reverse the second half, then weave
        # the two halves together.
        slow = fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        second, slow.next = slow.next, None
        prev = None
        while second:
            second.next, prev, second = prev, second, second.next
        first, second = head, prev
        while second:
            first.next, first = second, first.next
            second.next, second = first, second.next
