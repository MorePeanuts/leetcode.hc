from hc_runtime import ListNode


class Solution:
    def hasCycle(self, head: ListNode | None) -> bool:
        # Floyd's tortoise and hare: the fast pointer meets the slow one
        # exactly when the list has a cycle.
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                return True
        return False
