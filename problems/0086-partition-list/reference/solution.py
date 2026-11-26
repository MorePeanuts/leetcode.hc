from hc_runtime import ListNode


class Solution:
    def partition(self, head: ListNode | None, x: int) -> ListNode | None:
        small = small_tail = ListNode()
        large = large_tail = ListNode()
        while head:
            if head.val < x:
                small_tail.next = head
                small_tail = head
            else:
                large_tail.next = head
                large_tail = head
            head = head.next
        large_tail.next = None
        small_tail.next = large.next
        return small.next
