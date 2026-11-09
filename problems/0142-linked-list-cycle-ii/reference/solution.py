from hc_runtime import ListNode


class Solution:
    def detectCycle(self, head: ListNode | None) -> ListNode | None:
        # Floyd: once the pointers meet inside the cycle, the meeting point
        # and the head are the same distance from the cycle's first node.
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                while head is not slow:
                    head = head.next
                    slow = slow.next
                return head
        return None
